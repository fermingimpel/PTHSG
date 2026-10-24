// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseSpawnableActor.h"

ABaseSpawnableActor::ABaseSpawnableActor()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABaseSpawnableActor::BeginPlay()
{
	Super::BeginPlay();
	
}