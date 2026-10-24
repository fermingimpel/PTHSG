// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseSpawnableActor.h"

#include "Components/StaticMeshComponent.h"

ABaseSpawnableActor::ABaseSpawnableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseSpawnableActor::BeginPlay()
{
	Super::BeginPlay();

}
