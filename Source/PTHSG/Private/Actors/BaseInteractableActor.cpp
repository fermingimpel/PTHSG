// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseInteractableActor.h"
#include "Components/StaticMeshComponent.h"
#include "Controllers/BasePlayerController.h"
#include "GameFramework/Pawn.h"
#include "Spawners/BaseActorSpawner.h"

ABaseInteractableActor::ABaseInteractableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Root);
}

// it doesn't spawn anything, it asks the player controller to open the widget for its spawner
void ABaseInteractableActor::Interact_Implementation(AActor* Interactor)
{
	if (!IsValid(Spawner))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no Spawner assigned."), *GetName());
		return;
	}

	const APawn* InteractorPawn = Cast<APawn>(Interactor);

	if (!IsValid(InteractorPawn))
	{
		return;
	}

	ABasePlayerController* PlayerController = Cast<ABasePlayerController>(InteractorPawn->GetController());

	if (IsValid(PlayerController))
	{
		PlayerController->OpenSpawnUI(Spawner);
	}
}

