// Fill out your copyright notice in the Description page of Project Settings.


#include "Race.h"

#include "Engine/AssetManager.h"


void ARace::StartPlay()
{
	Super::StartPlay();

	check(GEngine != NULL);

	// Set the variable to the default values
	currentLap = 1;
	checkpointScore = 1;
	nextCheckpoint = 0;
	
	// Send a debug message to let the player know the gamemode has started
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("This is a Race"));
}




