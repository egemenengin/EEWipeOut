// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformMovement.h"

// Sets default values
APlatformMovement::APlatformMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformMovement::BeginPlay()
{
	Super::BeginPlay();

	StartingPosition = GetActorLocation();
	//Description = FString::Printf(TEXT("Name: %s\nCanMove: %d | Move Velocity: (%f,%f,%f)\nCanRotate: %d | RotateVelocity: (%f,%f,%f)"), 
	//							  *GetName(), CanMove, MoveVelocity.X, MoveVelocity.Y, MoveVelocity.Z,
	//							  CanRotate, RotatingVelocity.Roll, RotatingVelocity.Pitch, RotatingVelocity.Yaw);
	//UE_LOG(LogTemp, Display, TEXT("%s"), *Description);
}

// Called every frame
void APlatformMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CanMove)
	{
		MovePlatform(DeltaTime);
	}
	if(CanRotate)
	{
		RotatePlatform(DeltaTime);
	}
}
bool APlatformMovement::IsPlatformPassedCheckpoint() const
{
	return GetMovedDistance() > MaxDistance;

}
float APlatformMovement::GetMovedDistance() const
{
	return MovedDistance;
}
void APlatformMovement::MovePlatform(float DeltaTime)
{
	if(IsPlatformPassedCheckpoint())
	{
		StartingPosition = StartingPosition + (MoveVelocity.GetSafeNormal()*MaxDistance);
		SetActorLocation(StartingPosition);
		MoveVelocity = MoveVelocity * -1;
		MovedDistance = FVector::Dist(StartingPosition, GetActorLocation());

	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (MoveVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
		MovedDistance = FVector::Dist(StartingPosition, GetActorLocation());

	}
}
void APlatformMovement::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotatingVelocity * DeltaTime);
}