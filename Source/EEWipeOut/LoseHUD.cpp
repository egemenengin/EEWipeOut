// Fill out your copyright notice in the Description page of Project Settings.


#include "LoseHUD.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Kismet/KismetSystemLibrary.h"

bool ULoseHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if(PlayerControllerRef)
    {
        PlayerControllerRef->SetShowMouseCursor(true);
    }
    if(!ensure(MainMenuButton != nullptr) ) return false;
    if(!ensure(TryAgainButton != nullptr) ) return false;


    MainMenuButton->OnClicked.AddDynamic(this, &ULoseHUD::OnMainMenuClicked);
    TryAgainButton->OnClicked.AddDynamic(this, &ULoseHUD::OnTryAgainClicked);

    return bSuccess;
}

void ULoseHUD::OnMainMenuClicked()
{
    if(PlayerControllerRef)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

void ULoseHUD::OnTryAgainClicked()
{

    UGameplayStatics::OpenLevel(GetWorld(), "DemoMap");


}