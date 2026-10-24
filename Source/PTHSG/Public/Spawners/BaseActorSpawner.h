// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActorSpawner.generated.h"

UCLASS()
class PTHSG_API ABaseActorSpawner : public AActor
{
	GENERATED_BODY()
	
private:	

protected:
	virtual void BeginPlay() override;

public:	
	ABaseActorSpawner();

};
