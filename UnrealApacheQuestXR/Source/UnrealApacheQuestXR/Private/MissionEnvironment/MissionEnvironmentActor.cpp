// Copyright Sherwin Espela 2024. All Rights Reserved.


#include "MissionEnvironment/MissionEnvironmentActor.h"
#include "InputActionValue.h"

AMissionEnvironmentActor::AMissionEnvironmentActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Tags.Add(FName(ACTOR_TAG_MISSION_ENVIRONMENT));
}

void AMissionEnvironmentActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMissionEnvironmentActor::Move(const FInputActionValue& Value, FRotator ChopperRotation)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator Rotation = ChopperRotation;
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	float Speed = MovementSpeedMultiplier * GetWorld()->DeltaTimeSeconds;
	AddActorLocalOffset(FVector(-MovementVector.Y, -MovementVector.X, 0.f) * Speed);
}

void AMissionEnvironmentActor::SetMovementOffset(FVector Value)
{
	AddActorWorldOffset(-Value);
}
