// Copyright Sherwin Espela 2024. All Rights Reserved.


#include "Player/ChopperPawn.h"
#include "InputActionValue.h"

AChopperPawn::AChopperPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	ChopperMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ChopperMesh"));
	ChopperMesh->SetupAttachment(GetRootComponent());
}

void AChopperPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AChopperPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChopperPawn::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetActorRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	float Speed = MovementSpeedMultiplier * GetWorld()->DeltaTimeSeconds;
	AddActorLocalOffset(FVector(MovementVector.Y, MovementVector.X, GetActorLocation().Z) * Speed);
}

void AChopperPawn::Rotate(const FInputActionValue& Value)
{
	FVector2D RotateVector = Value.Get<FVector2D>();
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation.Yaw = RotateVector.X * YawOffsetAngle * GetWorld()->DeltaTimeSeconds;
	AddActorWorldRotation(CurrentRotation);
}
