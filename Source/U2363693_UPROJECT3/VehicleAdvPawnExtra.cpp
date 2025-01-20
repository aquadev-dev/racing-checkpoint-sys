// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleAdvPawnExtra.h"



// Sets default values
AVehicleAdvPawnExtra::AVehicleAdvPawnExtra() 
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Position = 0;
	CurrentLap = 1;
	CheckpointScore = 0;

	

	

}

// Called when the game starts or when spawned
void AVehicleAdvPawnExtra::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicleAdvPawnExtra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



