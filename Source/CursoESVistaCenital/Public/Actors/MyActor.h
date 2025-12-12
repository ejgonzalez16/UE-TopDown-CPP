// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class CURSOESVISTACENITAL_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Access to a variable or a function in unreal and blueprints
	// The category can be also without a subcategory, for example: Movement | Physics
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement | Physics")
	UStaticMesh* MyMesh;

	// Important: for Unreal management you need to put UPROPERTY
	UPROPERTY(EditAnywhere)
	UStaticMesh* MyOldMesh;
};
