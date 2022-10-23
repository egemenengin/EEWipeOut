// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WinHUD.generated.h"

/**
 * 
 */
UCLASS()
class EEWIPEOUT_API UWinHUD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget) )
	class UButton* MainMenuButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* QuitButton;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true") )
	class APlayerController* PlayerControllerRef;

	UFUNCTION()
	void OnMainMenuClicked();

	UFUNCTION()
	void OnQuitClicked();

};
