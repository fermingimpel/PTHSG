// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

UCLASS()
class PTHSG_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	UPROPERTY()
	class UActorSpawnerWidget* SpawnerWidget;

	// weak pointer in case the spawner gets destroyed while the UI is open
	TWeakObjectPtr<class ABaseActorSpawner> ActiveSpawner;

	UFUNCTION()
	void HandleSpawnConfirmed(int Amount, float LifeSpan);
	UFUNCTION()
	void HandleWidgetClosed();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<class UActorSpawnerWidget> SpawnerWidgetClass;

public:

	void OpenSpawnUI(class ABaseActorSpawner* Spawner);
	void CloseSpawnUI();

};
