// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GateControl.generated.h"


UCLASS()
class EEWIPEOUT_API AGateControl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGateControl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnyWhere, Category = "Gate Opening")
	bool IsOpen = false;
	UPROPERTY(EditAnyWhere, Category = "Gate Opening")
	float TimeClosed = 0;
	UPROPERTY(EditAnyWhere, Category = "Gate Opening")
	float MinTime = 3;
	UPROPERTY(EditAnyWhere, Category = "Gate Opening")
	float MaxTime = 6;
	UPROPERTY(VisibleAnyWhere, Category = "Gate Opening")
	bool TimerStarted = false;

	FTimerHandle TimerHandle;
	void GateBlockHandler();

};
