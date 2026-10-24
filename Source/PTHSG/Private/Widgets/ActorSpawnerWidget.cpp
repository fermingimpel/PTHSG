// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ActorSpawnerWidget.h"

#include "Components/Button.h"
#include "Components/SpinBox.h"

void UActorSpawnerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (IsValid(AmountInput))
	{
		AmountInput->SetMinValue(1.0f);
		AmountInput->SetMaxValue(static_cast<float>(MaxAmount));
		AmountInput->SetMinFractionalDigits(0);
		AmountInput->SetMaxFractionalDigits(0);
		AmountInput->SetDelta(1.0f);
	}

	if (IsValid(LifeSpanInput))
	{
		LifeSpanInput->SetMinValue(0.1f);
		LifeSpanInput->SetMaxValue(MaxLifeSpan);
		LifeSpanInput->SetMaxFractionalDigits(1);
	}

	if (IsValid(ConfirmButton))
	{
		ConfirmButton->OnClicked.AddDynamic(this, &UActorSpawnerWidget::HandleConfirmClicked);
	}

	if (IsValid(CancelButton))
	{
		CancelButton->OnClicked.AddDynamic(this, &UActorSpawnerWidget::HandleCancelClicked);
	}
}

void UActorSpawnerWidget::HandleConfirmClicked()
{
	int Amount = 0;
	float LifeSpan = 0.0f;

	if (TryReadInputs(Amount, LifeSpan))
	{
		OnSpawnConfirmed.Broadcast(Amount, LifeSpan);
	}
}

void UActorSpawnerWidget::HandleCancelClicked()
{
	OnWidgetClosed.Broadcast();
}

bool UActorSpawnerWidget::TryReadInputs(int& OutAmount, float& OutLifeSpan)
{
	if (!IsValid(AmountInput) || !IsValid(LifeSpanInput))
	{
		return false;
	}

	OutAmount = FMath::RoundToInt(AmountInput->GetValue());
	OutLifeSpan = LifeSpanInput->GetValue();

	return OutAmount >= 1 && OutAmount <= MaxAmount && OutLifeSpan > 0.0f && OutLifeSpan <= MaxLifeSpan;
}
