// Copyright Sherwin Espela 2024. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChopperController.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputComponent;
struct FInputActionValue;
class AVRPlayer;

/**
 * 
 */
UCLASS()
class UNREALAPACHEQUESTXR_API AChopperController : public APlayerController
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
	UInputAction* RotateAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
	UInputAction* IAAltitude;

protected:
	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);
	void SetAltitude(const FInputActionValue& Value);

private:
	UEnhancedInputComponent* EnhancedInputComponent;
};
