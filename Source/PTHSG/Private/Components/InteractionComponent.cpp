// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InteractionComponent.h"

#include "Engine/World.h"
#include "Interfaces/Interactable.h"
#include "Kismet/KismetSystemLibrary.h"

UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UInteractionComponent::TryInteract()
{
	AActor* Owner = GetOwner();
	UWorld* World = GetWorld();

	if (!IsValid(Owner) || !IsValid(World))
	{
		return false;
	}

	const FVector Start = Owner->GetActorLocation();
	const FVector End = Start + Owner->GetActorForwardVector() * InteractionDistance;

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(Owner);

	TArray<FHitResult> Hits;
	UKismetSystemLibrary::SphereTraceMulti(World, Start, End, TraceRadius, TraceChannel, false, ActorsToIgnore,
		bDrawDebug ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None, Hits, true);

	TSet<AActor*> InteractedActors;

	for (const FHitResult& Hit : Hits)
	{
		AActor* HitActor = Hit.GetActor();

		if (!IsValid(HitActor) || InteractedActors.Contains(HitActor) || !HitActor->Implements<UInteractable>())
		{
			continue;
		}

		InteractedActors.Add(HitActor);
		IInteractable::Execute_Interact(HitActor, Owner);
	}

	return !InteractedActors.IsEmpty();
}
