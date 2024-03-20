// Copyright Sherwin Espela 2024. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRPlayer.generated.h"

class AChopperPawn;
struct FInputActionValue;

UCLASS()
class UNREALAPACHEQUESTXR_API AVRPlayer : public APawn
{
	GENERATED_BODY()

public:
	AVRPlayer();

	virtual void Tick(float DeltaTime) override;
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveChopper(const FInputActionValue& Value);
	void RotateChopper(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Apache Chopper")
	TSubclassOf<AChopperPawn> ChopperPawnClass;

	UPROPERTY(BlueprintReadOnly, Category = "Apache Chopper")
	AChopperPawn* Chopper;
};
