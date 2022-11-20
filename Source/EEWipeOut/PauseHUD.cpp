// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseHUD.h"
#include "CoreMinimal.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Kismet/KismetSystemLibrary.h"

bool UPauseHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    if(!bSuccess) return false;

    if(!ensure(ContinueButton != nullptr)) return false;
    if(!ensure(MainMenuButton != nullptr)) return false;
    if(!ensure(MinutesText != nullptr)) return false;
    if(!ensure(SecondsText != nullptr)) return false;
    if(!ensure(TimeText != nullptr)) return false;



    ContinueButton->OnClicked.AddDynamic(this, &UPauseHUD::OnContinueClicked);
    MainMenuButton->OnClicked.AddDynamic(this, &UPauseHUD::OnMainMenuClicked);

    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    //IsOpen = false;
    return bSuccess;
}
void UPauseHUD::OnMainMenuClicked()
{
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}
void UPauseHUD::OnContinueClicked()
{
    this->SetVisibility(ESlateVisibility::Hidden);
    this->SetIsEnabled(false);
    UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerControllerRef);
  
}
bool UPauseHUD::GetIsOpen()
{
    return IsOpen;
}

void UPauseHUD::SetIsOpen(bool inp)
{
    IsOpen = inp;
}