// Copyright Sherwin Espela 2024. All Rights Reserved.

#include "Player/VRPlayer.h"
#include "Player/ChopperPawn.h"
#include "InputActionValue.h"

AVRPlayer::AVRPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AVRPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	if (ChopperPawnClass)
	{
		const FVector Location = { 0, 0, 0 };
		const FRotator Rotation = FRotator(0, 0, 0);
		Chopper = GetWorld()->SpawnActor<AChopperPawn>(ChopperPawnClass, Location, Rotation);
	}
}

void AVRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVRPlayer::MoveChopper(const FInputActionValue& Value)
{
	if (Chopper == nullptr) return;
	Chopper->Move(Value);
}

void AVRPlayer::RotateChopper(const FInputActionValue& Value)
{
	if (Chopper == nullptr) return;
	Chopper->Rotate(Value);
}

//void AVRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

