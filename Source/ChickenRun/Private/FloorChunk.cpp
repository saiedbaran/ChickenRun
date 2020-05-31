// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorChunk.h"
#include "Floor.h"
#include "Chicken.h"
#include "Kismet/KismetMathLibrary.h"
#include "LandingNode.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AFloorChunk::AFloorChunk()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFloorChunk::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AFloorChunk::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AFloorChunk::CalculateFloorTransform(FTransform& TransformLeft, FTransform& TransformMid,
                                          FTransform& TransformRight, float Pos_Y)
{
    TransformLeft = UKismetMathLibrary::MakeTransform(FVector(-1800.0f, Position_Y, 0),
                                                      FRotator::ZeroRotator,
                                                      FVector::OneVector);

    TransformMid = UKismetMathLibrary::MakeTransform(FVector(0, Position_Y, 0),
                                                     FRotator::ZeroRotator,
                                                     FVector::OneVector);

    TransformRight = UKismetMathLibrary::MakeTransform(FVector(1800.0f, Position_Y, 0),
                                                       FRotator::ZeroRotator,
                                                       FVector::OneVector);

    Pos_Y = Position_Y;
}

void AFloorChunk::DestroyMeshes()
{
    if (LandingNodes.Num() == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("LandingNodes is empty"));
        return;
    }
    for (auto LandingNode : LandingNodes)
    {
        LandingNode->Destroy();
    }

    Cast<AActor>(LeftFloor)->Destroy();
    Cast<AActor>(CenterFloor)->Destroy();
    Cast<AActor>(RightFloor)->Destroy();

    for (auto Prop : Props)
    {
        Prop->Destroy();
    }
}

void AFloorChunk::CheckDistanceToDestroy()
{
    if (!ChickenRef) { return; }
    auto MaxDistanceToChicken = Cast<AActor>(ChickenRef)->GetActorLocation().Y + MaxDistanceBackwardToChicken;
    if (GetActorLocation().Y >= MaxDistanceToChicken)
    {
        DestroyMeshes();
        Destroy();
    }
}

void AFloorChunk::GenerateLandingNode(bool IsWater)
{
    auto SpawnLocation = FVector(CurrentLandingNode_X, GetActorLocation().Y, CurrentLandingNode_Z);
    auto SpawnTransform = UKismetMathLibrary::MakeTransform(SpawnLocation,
        FRotator::ZeroRotator,
        FVector::ZeroVector);
    auto CurrentLandingNode = GetWorld()->SpawnActorDeferred<ALandingNode>(LandingNodeRef, SpawnTransform);
    if(CurrentLandingNode)
    {
        UGameplayStatics::FinishSpawningActor(CurrentLandingNode, SpawnTransform);
    }
    
    LandingNodes.Add(CurrentLandingNode);
    CurrentLandingNode_X += 200;
}
