// Fill out your copyright notice in the Description page of Project Settings.


#include "GH_Controller.h"
#include "Engine/World.h"


void UGH_Controller::NativeConstruct()
{
	Super::NativeConstruct();
	AGameModeBase* mode{ GetWorld()->GetAuthGameMode() };
	if (mode != nullptr)
	{
		gameMode = Cast<AlabyrinthGameModeBase>(mode);
	}
}

void UGH_Controller::NativeTick(const FGeometry& geometry, float deltaTime)
{
	Super::NativeTick(geometry, deltaTime);
	FString scoreStr{ FString::FromInt(gameMode->score) };

	scoreLabel->SetText(FText::FromString("Score: " + scoreStr));

	lifeProgress->SetPercent((float)gameMode->life*0.01f);
}
