// Fill out your copyright notice in the Description page of Project Settings.


#include "GateControl.h"



// Sets default values
AGateControl::AGateControl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//GateBlockObj = CreateDefaultSubobject<GateBlock>(TEXT("GateBlockComponent"));

	
	
}

// Called when the game starts or when spawned
void AGateControl::BeginPlay()
{
	Super::BeginPlay();
	TimeClosed = FMath::RandRange(MinTime, MaxTime);
}

// Called every frame
void AGateControl::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	if(!TimerStarted)
	{
		
		TimerStarted = true;
		//UE_LOG(LogTemp, Display, TEXT("TIMER STARTED %f"), TimeClosed);
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this ,&AGateControl::GateBlockHandler, TimeClosed, false);
		
	}
}

void AGateControl::GateBlockHandler()
{
		
		if(IsOpen)
		{	
			//UE_LOG(LogTemp, Display, TEXT("CLOSE"));
			SetActorHiddenInGame(true);
			SetActorEnableCollision(false);	
			IsOpen = false;
		}
		else
		{
			//UE_LOG(LogTemp, Display, TEXT("OPEN"));
			SetActorHiddenInGame(false);
			SetActorEnableCollision(true);
			IsOpen = true;
		}
		TimerStarted = false;

}
