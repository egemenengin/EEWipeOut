// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsHUD.generated.h"

/**
 * 
 */
UCLASS()
class EEWIPEOUT_API USettingsHUD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class USlider* MusicSlider;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class USlider* SoundSlider;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* BackButton;


};
