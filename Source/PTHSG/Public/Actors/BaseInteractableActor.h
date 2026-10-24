// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "BaseInteractableActor.generated.h"

UCLASS()
class PTHSG_API ABaseInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
private:	

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* StaticMesh;
	
	virtual void BeginPlay() override;

public:	
	ABaseInteractableActor();
	
	UFUNCTION(BlueprintCallable)
	virtual void Interact_Implementation(AActor* Interactor) override;
};
