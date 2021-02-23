// Fill out your copyright notice in the Description page of Project Settings.


#include "GH_Controller.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "CTopDown.h"


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

	if (gameMode->score >= 100) {
		FinalScoreLabel->SetText(FText::FromString("Score: " + scoreStr));
		gameOverLabel->SetText(FText::FromString("You win"));
		FinalScoreLabel->SetOpacity(1.f);
		gameOverLabel->SetOpacity(1.f);
		acum += deltaTime;
		if (acum >= 3)
		{
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
	}
	if (gameMode->life <= 0) {
		FinalScoreLabel->SetText(FText::FromString("Score: " + scoreStr));
		gameOverLabel->SetText(FText::FromString("Game Over"));
		FinalScoreLabel->SetOpacity(1.f);
		gameOverLabel->SetOpacity(1.f);
		acum += deltaTime;
		if (acum >= 3)
		{
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
	}
}

