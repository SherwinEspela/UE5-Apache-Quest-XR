// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ApacheController.h"
#include "Player/VRPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

void AApacheController::BeginPlay()
{
	Super::BeginPlay();

	VRPlayer = Cast<AVRPlayer>(GetPawn());

	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	PlayerSubsystem->AddMappingContext(InputMappingContext, 0);
}

void AApacheController::SetupInputComponent()
{

}
