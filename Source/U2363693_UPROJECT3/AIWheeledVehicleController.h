// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIWheeledVehicleController.generated.h"

/**
 * 
 */
UCLASS()
class U2363693_UPROJECT3_API AAIWheeledVehicleController : public AAIController
{
	GENERATED_BODY()

public:
	AAIWheeledVehicleController();

	// A cached BT component
	class UBehaviorTreeComponent* BehaviorTreeComp;
	// A Cached Blackboard Component
	class UBlackboardComponent* BlackboardComp;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;	
	
};
