// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/BasePlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Characters/BaseCharacter.h"
#include "Spawners/BaseActorSpawner.h"
#include "Widgets/ActorSpawnerWidget.h"

void ABasePlayerController::OpenSpawnUI(ABaseActorSpawner* Spawner)
{
	if (!IsValid(Spawner) || !SpawnerWidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s cannot open the spawner UI: missing spawner or SpawnerWidgetClass."), *GetName());
		return;
	}

	if (!IsValid(SpawnerWidget))
	{
		SpawnerWidget = CreateWidget<UActorSpawnerWidget>(this, SpawnerWidgetClass);

		if (!IsValid(SpawnerWidget))
		{
			return;
		}

		SpawnerWidget->OnSpawnConfirmed.AddDynamic(this, &ABasePlayerController::HandleSpawnConfirmed);
		SpawnerWidget->OnWidgetClosed.AddDynamic(this, &ABasePlayerController::HandleWidgetClosed);
	}

	if (SpawnerWidget->IsInViewport())
	{
		return;
	}

	ActiveSpawner = Spawner;
	SpawnerWidget->AddToViewport();

	if (ABaseCharacter* ControlledCharacter = Cast<ABaseCharacter>(GetPawn()))
	{
		ControlledCharacter->ResetMovementSpeed();
	}

	SetShowMouseCursor(true);
	SetInputMode(FInputModeUIOnly());
}

void ABasePlayerController::CloseSpawnUI()
{
	if (IsValid(SpawnerWidget))
	{
		SpawnerWidget->RemoveFromParent();
	}

	ActiveSpawner.Reset();

	SetShowMouseCursor(false);
	SetInputMode(FInputModeGameOnly());
}

void ABasePlayerController::HandleSpawnConfirmed(int Amount, float LifeSpan)
{
	if (ABaseActorSpawner* Spawner = ActiveSpawner.Get())
	{
		Spawner->SpawnActors(Amount, LifeSpan);
	}

	CloseSpawnUI();
}

void ABasePlayerController::HandleWidgetClosed()
{
	CloseSpawnUI();
}
