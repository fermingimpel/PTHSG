// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerInputDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PTHSG_API UPlayerInputDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inputs")
	class UInputAction* Move;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inputs")
	class UInputAction* Look;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inputs")
	class UInputAction* Jump;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inputs")
	class UInputAction* Run;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inputs")
	class UInputAction* Interact;
};
