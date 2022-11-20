// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameHUD.h"
#include "PauseHUD.h"
#include "LoseHUD.h"
#include "WinHUD.h"
#include "Components/BoxComponent.h"
// Sets default values

AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GameHUD = nullptr;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	check(PlayerControllerRef);
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerControllerRef);
	
	if(GameHUDClass && PauseHUDClass && WinHUDClass && LoseHUDClass)
	{
		GameHUD = CreateWidget<UGameHUD>(PlayerControllerRef, GameHUDClass);
		check(GameHUD);
		GameHUD->AddToPlayerScreen();

		PauseHUD = CreateWidget<UPauseHUD>(PlayerControllerRef, PauseHUDClass);
		check(PauseHUD);
		PauseHUD->AddToPlayerScreen();
		PauseHUD->SetVisibility(ESlateVisibility::Hidden);
    	PauseHUD->SetIsEnabled(false);

		WinHUD = CreateWidget<UWinHUD>(PlayerControllerRef, WinHUDClass);
		check(WinHUD);

		LoseHUD = CreateWidget<ULoseHUD>(PlayerControllerRef, LoseHUDClass);
		check(LoseHUD);
	}
	WinDoor = FindComponentByClass<UChildActorComponent>(); 
	WinCollider = WinDoor->GetChildActor()->FindComponentByClass<UBoxComponent>();
	WinCollider->OnComponentBeginOverlap.AddDynamic(this, &AGameManager::Win);
	//WinDoor->OnComponentBeginOverlap.AddDynamic(this, &AGameManager::Win);
	
	LoseCollider = FindComponentByClass<UBoxComponent>();
	LoseCollider->OnComponentBeginOverlap.AddDynamic(this, &AGameManager::Fall);
	UE_LOG(LogTemp, Display, TEXT("Win Collider: %s"), *(WinCollider->GetName()));
	UE_LOG(LogTemp, Display, TEXT("Lose Collider: %s"), *(LoseCollider->GetName()));
	PlayerControllerRef->SetShowMouseCursor(false);
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if( (PlayerControllerRef->WasInputKeyJustPressed(EKeys::P)) &&
	    (!PauseHUD->GetIsEnabled()) && !GameFinished ) 
	{

		PauseHUD->SetIsOpen(true);
		PauseHUD->SetVisibility(ESlateVisibility::Visible);
    	PauseHUD->SetIsEnabled(true);
		IsPaused = true;
		//UWidgetBlueprintLibrary::SetInputMode_GameAndUI();
		//SetInputMode_GameAndUIEx(APlayerController* PlayerContr...,UWidget* InWidgetToFocus,EMouseLockMode InMouseLockMode,bool bHideCursorDuringCapture)
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerControllerRef, PauseHUD, EMouseLockMode::LockOnCapture);
	}
		

	
	if( (!TimerStarted) && (!PauseHUD->GetIsEnabled()) && (!GameFinished) )
	{	
		
		TimerStarted = true;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this ,&AGameManager::TimeManager, 1, false);
		if(GetRemainingTime() <= 0)
		{
			Lose();
		}
	}
	
}

void AGameManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if(GameHUD)
	{
		GameHUD->RemoveFromParent();
		GameHUD = nullptr;
	}
	
}
void AGameManager::TimeManager()
{
	GameHUD->SetTime();
	TimerStarted = false;
}

float AGameManager::GetRemainingTime()
{
	return GameHUD->GetRemainingTime();
}

void AGameManager::Win(UPrimitiveComponent* a,AActor* b, UPrimitiveComponent* c, int32 d,bool e, const FHitResult& f)
{
	if( !GameFinished )
	{
		PlayerControllerRef->SetShowMouseCursor(true);
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerControllerRef, WinHUD, EMouseLockMode::LockOnCapture);
		WinHUD->AddToPlayerScreen();
		GameFinished = true;
		TimerStarted = false;
	}
		
}

void AGameManager::Lose()
{
	if( !GameFinished )
	{
		PlayerControllerRef->SetShowMouseCursor(true);
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerControllerRef, LoseHUD, EMouseLockMode::LockOnCapture);
		GameFinished = true;
		TimerStarted = false;
		LoseHUD->AddToPlayerScreen();
	}

}

void AGameManager::Fall(UPrimitiveComponent* a,AActor* b, UPrimitiveComponent* c, int32 d,bool e, const FHitResult& f)
{	
	Lose();
}



