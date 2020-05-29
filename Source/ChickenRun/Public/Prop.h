// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Prop.generated.h"

UCLASS()
class CHICKENRUN_API AProp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProp();
	bool SetMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Members
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Scene;

	UPROPERTY(EditAnywhere, Category = "Features")
	UStaticMesh* StaticMesh;
	
	bool bDark = false;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UMaterialInstanceDynamic* MaterialInstance;

	UPROPERTY(EditAnywhere, Category = "Features")
	UMaterialInterface* MaterialInterface;

	

protected:
	// Methods

	void DarkenMesh(UMaterialInstanceDynamic* MI);

	

};
