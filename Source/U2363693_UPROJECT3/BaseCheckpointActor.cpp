// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCheckpointActor.h"

#include "Race.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseCheckpointActor::ABaseCheckpointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create the mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComponent->SetupAttachment(RootComponent);

	//Register OnBeginOverlap function as an OnActorBeginOverlap delegate
	OnActorBeginOverlap.AddDynamic(this, &ABaseCheckpointActor::OnBeginOverlap);
	//Register OnEndOverlap function as an OnActorEndOverlap delegate
	OnActorEndOverlap.AddDynamic(this, &ABaseCheckpointActor::OnEndOverlap);
	//Register OnHit function as an OnActorHitOverlap delegate
	OnActorHit.AddDynamic(this, &ABaseCheckpointActor::OnHit);

	CheckpointNumber = 0;

}

// Called when the game starts or when spawned
void ABaseCheckpointActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCheckpointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCheckpointActor::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	// Get an instance of the Player Pawn
	AActor* Vehicle = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	// Get an instance of the Race GameMode
	ARace* Race = GetWorld()->GetAuthGameMode<ARace>();

	// If the OtherActor is equal to the Player pawn
	if (OtherActor == Vehicle)
	{
		// If the nextCheckpoint variable is equal to the number of the checkpoint
		if (Race->nextCheckpoint == CheckpointNumber)
		{
			Race->nextCheckpoint = CheckpointNumber + 1; // Increase the nextCheckpoint by 1
			Race->checkpointScore += CheckpointNumber; // Increase the checkpointScore by adding the checkpoint number
			// Send a debug message to let the player know the checkpoint has counted
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Checkpoint counted"));
			
		} else
		{
			// Send a debug message to let the player know the checkpoint has not counted
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, TEXT("Checkpoint Didn't Count"));
		}
		
	};
	
}

void ABaseCheckpointActor::OnEndOverlap(AActor * OverlappedActor, AActor * OtherActor)
{
	// Get an instance of the Player Pawn
	AActor* Vehicle = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	// If the OtherActor is equal to the Player pawn
	if (OtherActor == Vehicle)
	{
		// Send a debug message to say the overlap has ended
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("End Overlap"));
	};
	
}

void ABaseCheckpointActor::OnHit(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("A hit event"));
}

