// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseInteractableActor.h"
#include "Components/StaticMeshComponent.h"
#include "Spawners/BaseActorSpawner.h"

ABaseInteractableActor::ABaseInteractableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Root);
}

void ABaseInteractableActor::Interact_Implementation(AActor* Interactor)
{
	if (!IsValid(Spawner))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no Spawner assigned."), *GetName());
		return;
	}

	const int SpawnAmount = FMath::RandRange(MinSpawnAmount, MaxSpawnAmount);
	Spawner->SpawnActors(SpawnAmount);
}

void ABaseInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}
