// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseInteractableActor.generated.h"

UCLASS()
class PTHSG_API ABaseInteractableActor : public AActor
{
	GENERATED_BODY()
	
private:	

protected:
	virtual void BeginPlay() override;

public:	
	ABaseInteractableActor();
};
