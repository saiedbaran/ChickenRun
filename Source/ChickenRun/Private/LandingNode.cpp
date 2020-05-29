// Fill out your copyright notice in the Description page of Project Settings.


#include "LandingNode.h"

// Sets default values
ALandingNode::ALandingNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	Plane->SetRelativeLocation(FVector(0,0,-30));

}

// Called when the game starts or when spawned
void ALandingNode::BeginPlay()
{
	Super::BeginPlay();
	
	Plane->SetVisibility(true);
	
}

// Called every frame
void ALandingNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

