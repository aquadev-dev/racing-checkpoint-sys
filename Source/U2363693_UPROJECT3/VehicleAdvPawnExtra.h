// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Pawn.h"
#include "VehicleAdvPawnExtra.generated.h"



UCLASS()
class U2363693_UPROJECT3_API AVehicleAdvPawnExtra : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVehicleAdvPawnExtra();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Racing")
	int Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Racing")
	int CurrentLap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Racing")
	int CheckpointScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemsAI")
	UBehaviorTree* ItemsAI; 
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
