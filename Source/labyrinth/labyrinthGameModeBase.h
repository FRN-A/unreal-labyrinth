// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "labyrinthGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LABYRINTH_API AlabyrinthGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	int score = 0;

	UPROPERTY(EditAnywhere)
	int life{};
};
