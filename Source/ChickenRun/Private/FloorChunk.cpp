// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorChunk.h"
#include "Floor.h"


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

