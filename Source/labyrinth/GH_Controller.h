// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "labyrinthGameModeBase.h"
#include "Components/TextBlock.h"
#include "GH_Controller.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH_API UGH_Controller : public UUserWidget
{
	GENERATED_BODY()
	
	class AlabyrinthGameModeBase* gameMode;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* scoreLabel;

	void NativeConstruct() override;
	void NativeTick(const FGeometry& geometry, float deltaTime) override;
};
