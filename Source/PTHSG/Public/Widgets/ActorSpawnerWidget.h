// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActorSpawnerWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpawnConfirmed, int, Amount, float, LifeSpan);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSpawnerWidgetClosed);

UCLASS()
class PTHSG_API UActorSpawnerWidget : public UUserWidget
{
	GENERATED_BODY()

private:

	bool TryReadInputs(int& OutAmount, float& OutLifeSpan);

	UFUNCTION()
	void HandleConfirmClicked();
	UFUNCTION()
	void HandleCancelClicked();

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	class USpinBox* AmountInput;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	class USpinBox* LifeSpanInput;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	class UButton* ConfirmButton;
	UPROPERTY(BlueprintReadOnly, Category = "Widgets", meta = (BindWidget))
	class UButton* CancelButton;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Validation", meta = (ClampMin = "1"))
	int MaxAmount = 500;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Validation", meta = (ClampMin = "0.1"))
	float MaxLifeSpan = 3600.0f;

	virtual void NativeOnInitialized() override;

public:

	UPROPERTY(BlueprintAssignable, Category = "Spawner")
	FOnSpawnConfirmed OnSpawnConfirmed;

	UPROPERTY(BlueprintAssignable, Category = "Spawner")
	FOnSpawnerWidgetClosed OnWidgetClosed;

};
