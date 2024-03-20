// Copyright Sherwin Espela 2024. All Rights Reserved.

#include "Player/Apache.h"
#include "InputActionValue.h"

AApache::AApache()
{
	PrimaryActorTick.bCanEverTick = true;

	ChopperMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ChopperMesh"));
	ChopperMesh->SetupAttachment(GetRootComponent());
}

void AApache::BeginPlay()
{
	Super::BeginPlay();
	
}

void AApache::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AApache::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
}

void AApache::Rotate(const FInputActionValue& Value)
{
}
