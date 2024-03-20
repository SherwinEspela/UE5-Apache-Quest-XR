// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRPlayer.generated.h"

class AApache;

UCLASS()
class UNREALAPACHEQUESTXR_API AVRPlayer : public APawn
{
	GENERATED_BODY()

public:
	AVRPlayer();

	virtual void Tick(float DeltaTime) override;
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Apache Chopper")
	TSubclassOf<AApache> ApacheClass;

	UPROPERTY(BlueprintReadOnly, Category = "Apache Chopper")
	AApache* Apache;
};
