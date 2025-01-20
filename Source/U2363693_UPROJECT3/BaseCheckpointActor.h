// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseCheckpointActor.generated.h"

UCLASS()
class U2363693_UPROJECT3_API ABaseCheckpointActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseCheckpointActor();
	
	// Mesh Component so the checkpoints can be seen in the editor but not in game
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent *MeshComponent;

	// Cached Int that stored the number of the checkpoint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Checkpoint Number")
	int CheckpointNumber;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Begin Overlap functions
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	// End Overlap Function
	UFUNCTION()
	void OnEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

	// On Hit Function
	UFUNCTION()
	void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
