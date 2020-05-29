// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FloorObject = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorMesh"));
	SetRootComponent(FloorObject);
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();

	if(!FloorStaticMesh[FloorType]) {return;}
	SetMesh(FloorStaticMesh[FloorType]);
	
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloor::DarkenMesh(UMaterialInstanceDynamic* MI)
{
	FLinearColor OutColor;
	MI->GetVectorParameterValue(FName(TEXT("_darkness")), OutColor);
	OutColor.R -= .4f;

	MI->SetVectorParameterValue(FName(TEXT("_darkness")), OutColor);
}

void AFloor::SetMesh(UStaticMesh* SM)
{
	FloorObject->SetStaticMesh(SM);
	MaterialInstance = FloorObject->CreateDynamicMaterialInstance(0, ChickenColor);

	if(!bTraversable)
	{
		DarkenMesh(MaterialInstance);
	}
}

