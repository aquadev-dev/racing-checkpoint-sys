// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StartFinish.generated.h"

UCLASS()
class U2363693_UPROJECT3_API AStartFinish : public AActor
{
	GENERATED_BODY()
	
public:
	// Mesh Component so the checkpoints can be seen in the editor but not in game
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent *MeshComponent;
	// Sets default values for this actor's properties
	AStartFinish();

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
