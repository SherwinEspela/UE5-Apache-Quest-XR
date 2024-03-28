// Copyright Sherwin Espela 2024. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissionEnvironmentActor.generated.h"

#define ACTOR_TAG_MISSION_ENVIRONMENT TEXT("MissionEnvironment")

struct FInputActionValue;

UCLASS()
class UNREALAPACHEQUESTXR_API AMissionEnvironmentActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMissionEnvironmentActor();

public:
	void Move(const FInputActionValue& Value, FRotator ChopperRotation);
	void SetMovementOffset(FVector Value);

protected:
	virtual void BeginPlay() override;

protected:
	//Note: Apache reallife average speed is 293Km/hr
	UPROPERTY(EditAnywhere, Category = "Chopper Properties")
	float MovementSpeedMultiplier = 100.f;

};
