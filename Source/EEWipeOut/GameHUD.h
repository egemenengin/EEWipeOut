// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class EEWIPEOUT_API UGameHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:





	UPROPERTY(EditAnyWhere, Category = "TIME")
	float TotalTime = 500;
	UPROPERTY(EditAnyWhere, Category = "TIME")
	float RemainingTime = 500;

	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UProgressBar* RemainingBar;

	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* MinutesText;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* SecondsText;


	void HandleTimer();

};

