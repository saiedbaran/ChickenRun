// Fill out your copyright notice in the Description page of Project Settings.


#include "Prop.h"

// Sets default values
AProp::AProp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scene"));
	RootComponent = Scene;

}

bool AProp::SetMesh()
{
	if(!StaticMesh) {return false;}
	Scene->SetStaticMesh(StaticMesh);
	MaterialInstance = Scene->CreateDynamicMaterialInstance(0, MaterialInstance);

	if(bDark) {DarkenMesh(MaterialInstance);}
	return true;
}

// Called when the game starts or when spawned
void AProp::BeginPlay()
{
	Super::BeginPlay();

	if (!SetMesh()) return;
}

// Called every frame
void AProp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProp::DarkenMesh(UMaterialInstanceDynamic* MI)
{
	FLinearColor OutColor;
	MI->GetVectorParameterValue(FName(TEXT("_darkness")), OutColor);
	OutColor.R -= .4f;

	MI->SetVectorParameterValue(FName(TEXT("_darkness")), OutColor);
}

