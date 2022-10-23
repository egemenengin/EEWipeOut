// Fill out your copyright notice in the Description page of Project Settings.


#include "WinHUD.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Kismet/KismetSystemLibrary.h"

bool UWinHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    if(!ensure(MainMenuButton != nullptr) ) return false;
    if(!ensure(QuitButton != nullptr) ) return false;
    
    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    MainMenuButton->OnClicked.AddDynamic(this, &UWinHUD::OnMainMenuClicked);
    QuitButton->OnClicked.AddDynamic(this, &UWinHUD::OnQuitClicked);
    return bSuccess;
}

void UWinHUD::OnMainMenuClicked()
{
    if(PlayerControllerRef)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

void UWinHUD::OnQuitClicked()
{
    if(PlayerControllerRef)
    {
        UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);  
    }



}