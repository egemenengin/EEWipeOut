// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseHUD.generated.h"

/**
 * 
 */
UCLASS()
class EEWIPEOUT_API UPauseHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

public:
	
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UButton* ContinueButton;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UButton* MainMenuButton;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* MinutesText;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* SecondsText;
	UPROPERTY(EditAnyWhere, meta = (BindWidget))
	class UTextBlock* TimeText;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class APlayerController* PlayerControllerRef;



	bool IsOpen;
	void SetIsOpen(bool inp);

	bool GetIsOpen();
	UFUNCTION()
	void OnContinueClicked();
	UFUNCTION()
	void OnMainMenuClicked();

};
