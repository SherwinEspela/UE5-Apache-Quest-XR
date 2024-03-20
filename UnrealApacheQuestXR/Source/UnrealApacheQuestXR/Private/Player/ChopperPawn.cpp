// Copyright Sherwin Espela 2024. All Rights Reserved.


#include "Player/ChopperPawn.h"
#include "InputActionValue.h"

AChopperPawn::AChopperPawn()
{
	//PrimaryActorTick.bCanEverTick = true;

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
	if (Controller == nullptr) return;

	FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(ForwardDirection, MovementVector.Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void AChopperPawn::Rotate(const FInputActionValue& Value)
{
}
