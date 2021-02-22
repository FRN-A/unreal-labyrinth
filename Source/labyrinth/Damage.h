// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Damage.generated.h"

UCLASS()
class LABYRINTH_API ADamage : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	int damage{ 10 };


public:	
	// Sets default values for this actor's properties
	ADamage();
	int GetDamage();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
