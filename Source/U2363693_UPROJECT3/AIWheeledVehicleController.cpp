// Fill out your copyright notice in the Description page of Project Settings.


#include "AIWheeledVehicleController.h"

#include "VehicleAdvPawnExtra.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIWheeledVehicleController::AAIWheeledVehicleController()
{
	//BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));

	//BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardTreeComp"));
}

void AAIWheeledVehicleController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//AVehicleAdvPawnExtra* AIVehicle = Cast<AVehicleAdvPawnExtra>(InPawn);

	//if (AIVehicle->ItemsAI->BlackboardAsset)
	//{
		//BlackboardComp->InitializeBlackboard(*AIVehicle->ItemsAI->BlackboardAsset);
	//}

	//BehaviorTreeComp->StartTree(*AIVehicle->ItemsAI);
}

void AAIWheeledVehicleController::Tick(float DeltaTime)
{
	
}

