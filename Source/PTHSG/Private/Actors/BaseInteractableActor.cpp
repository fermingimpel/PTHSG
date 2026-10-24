// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseInteractableActor.h"

ABaseInteractableActor::ABaseInteractableActor()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABaseInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}
