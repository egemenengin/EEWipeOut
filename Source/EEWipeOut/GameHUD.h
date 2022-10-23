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
protected:
	virtual bool Initialize() override;
public:

	UPROPERTY(EditAnyWhere, Category = "TIME")
	float TotalTime = 120;
	UPROPERTY(EditAnyWhere, Category = "TIME")
	float RemainingTime = 120;

	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UProgressBar* RemainingBar;

	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* MinutesText;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* SecondsText;

	UFUNCTION()
	float GetRemainingTime();
	
	void SetTime();

};

