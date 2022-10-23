// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"

bool UGameHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    if(!bSuccess) return false;

    if(!ensure(RemainingBar != nullptr)) return false;
    if(!ensure(MinutesText != nullptr)) return false;
    if(!ensure(SecondsText != nullptr)) return false;
    int remainingMin = RemainingTime / 60;
    int remainingSec = (int)RemainingTime % 60;
    MinutesText->SetText(FText::AsNumber(remainingMin));
    SecondsText->SetText(FText::AsNumber(remainingSec));
    return bSuccess;
}

void UGameHUD::SetTime()
{
    RemainingTime -=1;
    int remainingMin = RemainingTime / 60;
    int remainingSec = (int)RemainingTime % 60;
    RemainingBar->SetPercent(RemainingTime / TotalTime);
    MinutesText->SetText(FText::AsNumber(remainingMin));
    SecondsText->SetText(FText::AsNumber(remainingSec));
}

float UGameHUD::GetRemainingTime()
{
    return RemainingTime;
}
