// Fill out your copyright notice in the Description page of Project Settings.
#include "MainMenuHUD.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Kismet/KismetSystemLibrary.h"


bool UMainMenuHUD::Initialize()
{

    const bool bSuccess = Super::Initialize();
    if(!bSuccess) return false;

    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if(PlayerControllerRef)
    {
        PlayerControllerRef->SetShowMouseCursor(true);
    }

    if(!ensure(StartButton != nullptr)) return false;
    if(!ensure(SettingsButton != nullptr)) return false;
    if(!ensure(InfoButton != nullptr)) return false;
    if(!ensure(QuitButton != nullptr)) return false;

    if(!ensure(InfoPanel != nullptr)) return false;
    if(!ensure(CloseInfoPanelButton != nullptr)) return false;

    StartButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnStartClicked);
    SettingsButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnSettingsClicked);
    InfoButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnInfoClicked);
    QuitButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnQuitClicked);

    CloseInfoPanelButton->OnClicked.AddDynamic(this,&UMainMenuHUD::OnCloseInfoClicked);

    return bSuccess;
}
void UMainMenuHUD::OnStartClicked()
{
   if(PlayerControllerRef)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "DemoMap");
    //UGameplayStatics::OpenLevel(GetWorld(), TEXT("World'/Game/Maps/Level1.Level1'"), TRAVEL_Absolute); 
}

void UMainMenuHUD::OnSettingsClicked()
{

    //UGameplayStatics::OpenLevel(GetWorld(), "");
}

void UMainMenuHUD::OnInfoClicked()
{
    InfoPanel->SetVisibility(ESlateVisibility::Visible);
    InfoPanel->SetIsEnabled(true);
}

void UMainMenuHUD::OnQuitClicked()
{
    if(PlayerControllerRef)
    {
        UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);
    }
}

void UMainMenuHUD::OnCloseInfoClicked()
{
    InfoPanel->SetVisibility(ESlateVisibility::Hidden);
    InfoPanel->SetIsEnabled(false);
}

