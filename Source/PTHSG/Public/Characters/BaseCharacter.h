// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

struct FInputActionValue;

UCLASS()
class PTHSG_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

private:

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	class UInputMappingContext* DefaultInputMappingContext;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	class UPlayerInputDataAsset* PlayerInputDataAsset;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UInteractionComponent* InteractionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float BaseMovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float RunningMovementSpeed;
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnMovePressed(const FInputActionValue& Value);
	UFUNCTION()
	void OnLookPressed(const FInputActionValue& Value);
	UFUNCTION()
	void OnJumpPressed();
	UFUNCTION()
	void OnRunPressed();
	UFUNCTION()
	void OnRunReleased();
	UFUNCTION()
	void OnInteractPressed();
	

public:	
	ABaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
