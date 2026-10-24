// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseInteractableActor.h"

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
	UE_LOG(LogTemp,Warning,TEXT("AAAAAAAAAAAAA"));
}

void ABaseInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}
