// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSpawnableActor.generated.h"

UCLASS()
class PTHSG_API ABaseSpawnableActor : public AActor
{
	GENERATED_BODY()

private:

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* StaticMesh;

public:
	ABaseSpawnableActor();

};
