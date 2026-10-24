// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawners/BaseActorSpawner.h"

ABaseActorSpawner::ABaseActorSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABaseActorSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}
