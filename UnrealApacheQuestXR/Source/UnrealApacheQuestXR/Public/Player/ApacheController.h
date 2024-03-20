// Copyright Sherwin Espela 2024. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ApacheController.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputComponent;
struct FInputActionValue;
class AVRPlayer;

// TODO: remove/delete later

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Input")
	UInputAction* RotateAction;

protected:
	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);

private:
	UEnhancedInputComponent* EnhancedInputComponent;

};
