// Fill out your copyright notice in the Description page of Project Settings.


#include "Chicken.h"

// Sets default values
AChicken::AChicken()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Chicken = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Chicken"));

}

// Called when the game starts or when spawned
void AChicken::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChicken::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChicken::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

