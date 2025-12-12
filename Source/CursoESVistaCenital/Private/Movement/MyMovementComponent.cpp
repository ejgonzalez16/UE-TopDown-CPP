
#include "Movement/MyMovementComponent.h"

UMyMovementComponent::UMyMovementComponent()
{
	// permission to do ticks
	PrimaryComponentTick.bCanEverTick = true;
}

void UMyMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// To avoid move when begins play
	NextLocation = GetOwner()->GetActorLocation();
	SetComponentTickEnabled(false);
}

void UMyMovementComponent::MoveToLocation(const FVector& NewLocation)
{
	NextLocation = NewLocation;
	SetComponentTickEnabled(true);
}

void UMyMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Distance vector between actor location and the objective location
	FVector Movement = NextLocation - GetOwner()->GetActorLocation();
	// Normalize vector to get a unit vector
	// The normalization of a vector -> To have the same magnitude of movement in any direction
	Movement.Normalize();
	// In base a physics formula Space = Speed*Time
	// DeltaTime is the time between two frames
	Movement *= (Speed * DeltaTime);

	// The movement is upper than the space that remains to move -> 
	// if the actor move, it will pass the NextLocation and generate a wierd effect
	if (Movement.Size() > (NextLocation - GetOwner()->GetActorLocation()).Size()) {
		// Put exactly in the NextLocation
		GetOwner()->SetActorLocation(NextLocation);
		SetComponentTickEnabled(false);
		return;
	}
	// if the movement is lower than the space that remains to move
	GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + Movement);
}
