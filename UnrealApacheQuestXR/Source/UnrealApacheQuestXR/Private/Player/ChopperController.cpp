// Copyright Sherwin Espela 2024. All Rights Reserved.


#include "Player/ChopperController.h"
#include "Player/VRPlayer.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

void AChopperController::BeginPlay()
{
	Super::BeginPlay();

	VRPlayer = Cast<AVRPlayer>(GetPawn());

	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	PlayerSubsystem->AddMappingContext(InputMappingContext, 0);
}

void AChopperController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AChopperController::Move);
	EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &AChopperController::Rotate);
}

void AChopperController::Move(const FInputActionValue& Value)
{
	if (VRPlayer == nullptr) return;
	VRPlayer->MoveChopper(Value);
}

void AChopperController::Rotate(const FInputActionValue& Value)
{
	if (VRPlayer == nullptr) return;
	VRPlayer->RotateChopper(Value);
}
