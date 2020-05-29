// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

class AFloorChunk;

UCLASS()
class CHICKENRUN_API AFloor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AFloor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Members:

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* FloorObject;

    UPROPERTY(EditAnywhere)
    int FloorType;

    UPROPERTY(VisibleAnywhere)
    UMaterialInstanceDynamic* MaterialInstance;

    UPROPERTY(EditAnywhere)
    bool bTraversable;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AFloorChunk> FloorChunk;

    UPROPERTY(EditAnywhere, Category = "Features")
    UMaterialInterface* ChickenColor;

    UPROPERTY(EditAnywhere, Category = "Features")
    TArray<UStaticMesh*> FloorStaticMesh;
    

protected:
    // Methods:

    void DarkenMesh(UMaterialInstanceDynamic* MI);

    void SetMesh(UStaticMesh* SM);
};
