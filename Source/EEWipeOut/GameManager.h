// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "GameManager.generated.h"

UCLASS()
class EEWIPEOUT_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	//GAMEHUD
	UPROPERTY(EditAnyWhere)
	TSubclassOf<class UGameHUD> GameHUDClass;
	UPROPERTY()
	class UGameHUD* GameHUD;
	
	//PAUSEHUD
	UPROPERTY(EditAnyWhere)
	TSubclassOf<class UPauseHUD> PauseHUDClass;
	UPROPERTY()
	class UPauseHUD* PauseHUD;

	//LOSEHUD
	UPROPERTY(EditAnyWhere)
	TSubclassOf<class ULoseHUD> LoseHUDClass;
	UPROPERTY()
	class ULoseHUD* LoseHUD;

	//WINHUD
	UPROPERTY(EditAnyWhere)
	TSubclassOf<class UWinHUD> WinHUDClass;
	UPROPERTY()
	class UWinHUD* WinHUD;


	UPROPERTY(VisibleAnyWhere, Category = "Timer Handle")
	bool TimerStarted = false;

	UPROPERTY(VisibleAnyWhere, Category = "Timer Handle")
	bool IsPaused = false;

	FTimerHandle TimerHandle;


	UPROPERTY(EditAnyWhere, Category = "Game Ending")
	bool TimeIsUp;
	UPROPERTY(EditAnyWhere, Category = "Game Ending")
	bool GameFinished;
	APlayerController* PlayerControllerRef;

	UFUNCTION()
	float GetRemainingTime();
	
	UFUNCTION()
	void TimeManager();

public:
	UPROPERTY()
	UChildActorComponent* WinDoor;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = Collision, meta = (AllowPrivateAccess = "true") )
	class UBoxComponent* WinCollider;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = Collision, meta = (AllowPrivateAccess = "true") )
	class UBoxComponent* LoseCollider;

	UFUNCTION()
	void Win(UPrimitiveComponent* a,AActor* b, UPrimitiveComponent* c, int32 d,bool e, const FHitResult& f);

	UFUNCTION()
	void Lose();

	UFUNCTION()
	void Fall(UPrimitiveComponent* a,AActor* b, UPrimitiveComponent* c, int32 d,bool e, const FHitResult& f);



};
