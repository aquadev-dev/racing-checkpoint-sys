// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Race.generated.h"

/**
 * 
 */
UCLASS()
class U2363693_UPROJECT3_API ARace : public AGameModeBase
{
	GENERATED_BODY()
public:
	// Cached Int for storing the currentLap the player is on
	UPROPERTY(EditAnywhere)
	int currentLap;
	// Cached Int for storing the checkpointScore of the player
	UPROPERTY(EditAnywhere)
	int checkpointScore;
	// Cached Int for storing the next checkpoint the player has to go to
	UPROPERTY(EditAnywhere)
	int nextCheckpoint;

	virtual void StartPlay() override;
	
};
