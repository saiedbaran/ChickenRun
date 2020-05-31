// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorChunk.generated.h"

class ALandingNode;
class AFloor;
class AChicken;

UCLASS()
class CHICKENRUN_API AFloorChunk : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AFloorChunk();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Members

    UPROPERTY(EditAnywhere)
    TSubclassOf<AFloor> LeftFloor;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AFloor> RightFloor;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AFloor> CenterFloor;

    UPROPERTY(VisibleAnywhere)
    TArray<AActor*> LandingNodes;

    UPROPERTY(VisibleAnywhere)
    TArray<AActor*> Props;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AChicken> ChickenRef;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ALandingNode> LandingNodeRef;

    float Position_Y;
    float MaxDistanceBackwardToChicken = 2000;
    float CurrentLandingNode_X = -800;
    float CurrentLandingNode_Z;

protected:
    void CalculateFloorTransform(FTransform &TransformLeft, FTransform &TransformMid,
        FTransform &TransformRight, float Pos_Y);

    void DestroyMeshes();
    void CheckDistanceToDestroy();

    void GenerateLandingNode(bool IsWater);
};
