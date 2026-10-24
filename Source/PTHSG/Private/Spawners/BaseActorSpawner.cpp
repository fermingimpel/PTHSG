// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawners/BaseActorSpawner.h"

#include "Actors/BaseSpawnableActor.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"

ABaseActorSpawner::ABaseActorSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
	SetRootComponent(SpawnArea);
}

void ABaseActorSpawner::SpawnActors(int Amount, float LifeSpan)
{
	UWorld* World = GetWorld();

	if (!IsValid(World) || !SpawnableActorClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s cannot spawn: missing world or SpawnableActorClass."), *GetName());
		return;
	}

	if (Amount <= 0 || LifeSpan <= 0.0f)
	{
		return;
	}

	const FVector Extent = SpawnArea->GetScaledBoxExtent();
	const FTransform AreaTransform = SpawnArea->GetComponentTransform();

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	for (int i = 0; i < Amount; i++)
	{
		const FVector LocalLocation = FMath::RandPointInBox(FBox(-Extent, Extent));
		const FVector SpawnLocation = AreaTransform.TransformPositionNoScale(LocalLocation);

		ABaseSpawnableActor* SpawnedActor = World->SpawnActor<ABaseSpawnableActor>(SpawnableActorClass, SpawnLocation, FRotator::ZeroRotator, SpawnParameters);

		if (IsValid(SpawnedActor))
		{
			SpawnedActor->SetLifeSpan(LifeSpan);
		}
	}
}
