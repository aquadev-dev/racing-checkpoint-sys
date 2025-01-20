// Fill out your copyright notice in the Description page of Project Settings.


#include "StartFinish.h"

#include "Race.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AStartFinish::AStartFinish()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComponent->SetupAttachment(RootComponent);

	//Register OnBeginOverlap function as an OnActorBeginOverlap delegate
	OnActorBeginOverlap.AddDynamic(this, &AStartFinish::OnBeginOverlap);
	//Register OnEndOverlap function as an OnActorEndOverlap delegate
	OnActorEndOverlap.AddDynamic(this, &AStartFinish::OnEndOverlap);
	//Register OnHit function as an OnActorHitOverlap delegate
	OnActorHit.AddDynamic(this, &AStartFinish::OnHit);

}

// Called when the game starts or when spawned
void AStartFinish::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStartFinish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStartFinish::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	// Get an instance of the Player Pawn
	AActor* Vehicle = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	// Get an instance of the Race GameMode
	ARace *currentRace = GetWorld()->GetAuthGameMode<ARace>();
	// Get the name of the current level running 
	FString currentLevel = UGameplayStatics::GetCurrentLevelName(GetWorld(), true);
	// Convert the String to the type of FName
	FName currentLevelName = FName(*currentLevel);

	// If the OtherActor is equal to the Player pawn
	if (OtherActor == Vehicle)
	{
		// If the current checkpoint score is 0 and the currentLap is 1 
		if (currentRace->checkpointScore == 0 && currentRace->currentLap == 1)
		{
			// Print debug messages to show the race has started and that the player is on to lap 1
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Yellow, TEXT("Race Started"));
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Onto Lap 1"));
		}
		// If the current checkpointScore is equal to 79 (Amount require to complete lap) and currentLap is 1
		else if (currentRace->checkpointScore == 79 && currentRace->currentLap == 1)
		{
			// Update the currentLap by 1
			currentRace->currentLap += 1;
			// Reset the checkpointScore to 1
			currentRace->checkpointScore = 1;
			// Reset the nextCheckpoint to 0
			currentRace->nextCheckpoint = 0;
			// Print debug message that the player is on to lap 2
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Onto Lap 2"));
			
			
		}
		// If the current checkpointScore is equal to 79 (Amount require to complete lap) and currentLap is 2
		else if (currentRace->checkpointScore == 79 && currentRace->currentLap == 2)
		{
			// Update the currentLap by 1
			currentRace->currentLap += 1;
			// Reset the checkpointScore to 1
			currentRace->checkpointScore = 1;
			// Reset the nextCheckpoint to 0
			currentRace->nextCheckpoint = 0;
			// Print debug message that the player is on to lap 3
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Onto Lap 3"));
			
			
		}
		// If the current checkpointScore is equal to 79 (Amount require to complete lap) and currentLap is 3
		else if (currentRace->checkpointScore == 79 && currentRace->currentLap == 3)
		{
			// Print debug message to show the race has ended 
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Yellow, TEXT("Race Finished"));
			// Reset the level
			UGameplayStatics::OpenLevel(GetWorld(), currentLevelName, true);
			
		}
		else
		{
			// Print debug message to show the lap didn't count
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Lap Didn't Count"));
		}
		
	};
	
}

void AStartFinish::OnEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	// Get an instance of the Player Pawn
	AActor* Vehicle = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	// If the OtherActor is equal to the Player pawn
	if (OtherActor == Vehicle)
	{
		// Print debug message to show End Overlap
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("End Overlap"));
	};
	
}

void AStartFinish::OnHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("A hit event"));
}


