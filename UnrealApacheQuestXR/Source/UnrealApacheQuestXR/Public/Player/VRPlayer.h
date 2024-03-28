// Copyright Sherwin Espela 2024. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VRPlayer.generated.h"

class AChopperPawn;
class AMissionEnvironmentActor;
struct FInputActionValue;

UCLASS()
class UNREALAPACHEQUESTXR_API AVRPlayer : public APawn
{
	GENERATED_BODY()

public:
	AVRPlayer();
	virtual void Tick(float DeltaTime) override;

public:
	void MoveChopper(const FInputActionValue& Value);
	void RotateChopper(const FInputActionValue& Value);
	void SetChopperAltitude(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Apache Chopper")
	TSubclassOf<AChopperPawn> ChopperPawnClass;

	UPROPERTY(BlueprintReadOnly, Category = "Apache Chopper")
	AChopperPawn* Chopper;

private:
	AMissionEnvironmentActor* MissionEnvironment;
};
