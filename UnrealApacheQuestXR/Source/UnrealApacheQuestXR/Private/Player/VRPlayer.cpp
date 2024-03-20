// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/VRPlayer.h"
#include "Player/Apache.h"

AVRPlayer::AVRPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AVRPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	if (ApacheClass)
	{
		const FVector Location = { 0, 0, 0 };
		const FRotator Rotation = FRotator(0, 0, 0);
		Apache = GetWorld()->SpawnActor<AApache>(ApacheClass, Location, Rotation);
	}
}

void AVRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AVRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

