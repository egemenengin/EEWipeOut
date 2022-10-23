// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoseHUD.generated.h"

/**
 * 
 */
UCLASS()
class EEWIPEOUT_API ULoseHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

public:
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* MainMenuButton;
	
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* TryAgainButton;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class APlayerController* PlayerControllerRef;
	UFUNCTION()
	void OnMainMenuClicked();

	UFUNCTION()
	void OnTryAgainClicked();

};
