// Include this file only once
#pragma once

#include "CoreMinimal.h"
// Extra code for unreal engine
#include "MyMovementComponent.generated.h"

// The specifier is to put the component in the list of components and assign to an actor
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
// Define the module, adds to the API
// All the class that heredates from U... needs to have a U at the beggining
class CURSOESVISTACENITAL_API UMyMovementComponent : public UActorComponent
{
	// Generate the additional things that UE needs to run with C++
	GENERATED_BODY()

public:
	UMyMovementComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector NextLocation;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 100.0f;

	// Called every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Non modificable argument and the reference to avoid copy the vector
	UFUNCTION(BlueprintCallable)
	void MoveToLocation(const FVector& NewLocation);
};