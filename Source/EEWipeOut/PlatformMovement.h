// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformMovement.generated.h"

UCLASS()
class EEWIPEOUT_API APlatformMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnyWhere, Category = "ABOUT")
	FString Description = "";
	
	//	MOVE PLATFORM {
	UPROPERTY(VisibleAnyWhere, Category = "Move Platform")
	FVector StartingPosition = FVector(0,0,0);
	UPROPERTY(EditAnyWhere, Category = "Move Platform")
	FVector MoveVelocity = FVector(0,0,0);
	UPROPERTY(EditAnyWhere, Category = "Move Platform")
	float MaxDistance = 500;
	UPROPERTY(VisibleAnyWhere, Category = "Move Platform")
	float MovedDistance = -1;
	UPROPERTY(EditAnyWhere, Category = "Move Platform")
	bool CanMove = false;
	
	float GetMovedDistance() const;
	bool IsPlatformPassedCheckpoint() const;
	void MovePlatform(float DeltaTime);
	//	}

	//	ROTATE PLATFORM {
	UPROPERTY(EditAnyWhere, Category = "Rotate Platform")
	FRotator RotatingVelocity = FRotator(0,0,0);
	UPROPERTY(EditAnyWhere, Category = "Rotate Platform")
	bool CanRotate = false;

	void RotatePlatform(float DeltaTime);
	//	}
};
