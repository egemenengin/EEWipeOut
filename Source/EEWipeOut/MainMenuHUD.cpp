// Fill out your copyright notice in the Description page of Project Settings.
#include "MainMenuHUD.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"

bool UMainMenuHUD::Initialize()
{
    const bool bSuccess = Super::Initialize();
    if(!bSuccess) return false;

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
    //UGameplayStatics::OpenLevel(GetWorld(), "Level2");
    //UGameplayStatics::OpenLevel(GetWorld(), TEXT("World'/Game/Maps/Level1.Level1'"), TRAVEL_Absolute); 
}

void UMainMenuHUD::OnSettingsClicked()
{

}

void UMainMenuHUD::OnInfoClicked()
{

}

void UMainMenuHUD::OnQuitClicked()
{

}

void UMainMenuHUD::OnCloseInfoClicked()
{

}

