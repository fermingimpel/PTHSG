// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActorSpawner.generated.h"

UCLASS()
class PTHSG_API ABaseActorSpawner : public AActor
{
	GENERATED_BODY()

private:

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* SpawnArea;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawner")
	TSubclassOf<class ABaseSpawnableActor> SpawnableActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawner", meta = (ClampMin = "0.1"))
	float SpawnedActorLifeSpan = 10.0f;

	virtual void BeginPlay() override;

public:
	ABaseActorSpawner();

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	void SpawnActors(int Amount);

};
