// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ApacheController.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputComponent;
struct FInputActionValue;
class AVRPlayer;

/**
 * 
 */
UCLASS()
class UNREALAPACHEQUESTXR_API AApacheController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	AVRPlayer* VRPlayer;

protected:
	// Player Inputs
	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	UInputMappingContext* InputMappingContext;

};
