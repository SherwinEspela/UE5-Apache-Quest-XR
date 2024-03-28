// Copyright Sherwin Espela 2024. All Rights Reserved.

#include "Player/VRPlayer.h"
#include "Player/ChopperPawn.h"
#include "InputActionValue.h"
#include "MissionEnvironment/MissionEnvironmentActor.h"
#include "Kismet/GameplayStatics.h"

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

	TArray<AActor*> MissionEnvironmentActors;
	UGameplayStatics::GetAllActorsWithTag(this, FName(ACTOR_TAG_MISSION_ENVIRONMENT), MissionEnvironmentActors);

	if (MissionEnvironmentActors.Num() > 0)
	{
		MissionEnvironment = CastChecked<AMissionEnvironmentActor>(MissionEnvironmentActors[0]);
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

void AVRPlayer::SetChopperAltitude(const FInputActionValue& Value)
{
	if (Chopper == nullptr) return;
	Chopper->Altitude(Value);
}
