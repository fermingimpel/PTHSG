// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "DataAssets/PlayerInputDataAsset.h"
#include "GameFramework/CharacterMovementComponent.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->MaxWalkSpeed = BaseMovementSpeed;
}

void ABaseCharacter::OnMovePressed(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	
	if (IsValid(Controller))
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

		const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardVector, MovementVector.Y);
		AddMovementInput(RightVector, MovementVector.X);
	}
}

void ABaseCharacter::OnLookPressed(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();
	
	if (IsValid(Controller))
	{
		AddControllerYawInput(LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}
}

void ABaseCharacter::OnJumpPressed()
{
	Jump();
}

void ABaseCharacter::OnRunPressed()
{
	GetCharacterMovement()->MaxWalkSpeed = RunningMovementSpeed;
}

void ABaseCharacter::OnRunReleased()
{
	GetCharacterMovement()->MaxWalkSpeed = BaseMovementSpeed;
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (IsValid(DefaultInputMappingContext))
	{
		const APlayerController* PlayerController = Cast<APlayerController>(GetController());
		if (IsValid(PlayerController))
		{
			UEnhancedInputLocalPlayerSubsystem* InputPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
			if (IsValid(InputPlayerSubsystem))
			{
				InputPlayerSubsystem->ClearAllMappings();
				InputPlayerSubsystem->AddMappingContext(DefaultInputMappingContext, 0);
			}
		}
	}
	
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!EIC || !PlayerInputDataAsset)
	{
		return;
	}

	EIC->BindAction(PlayerInputDataAsset->Move, ETriggerEvent::Triggered, this, &ABaseCharacter::OnMovePressed);
	
	EIC->BindAction(PlayerInputDataAsset->Look, ETriggerEvent::Triggered, this, &ABaseCharacter::OnLookPressed);
	
	EIC->BindAction(PlayerInputDataAsset->Jump, ETriggerEvent::Started, this, &ABaseCharacter::OnJumpPressed);
	
	EIC->BindAction(PlayerInputDataAsset->Run, ETriggerEvent::Started, this, &ABaseCharacter::OnRunPressed);
	EIC->BindAction(PlayerInputDataAsset->Run, ETriggerEvent::Completed, this, &ABaseCharacter::OnRunReleased);
}

