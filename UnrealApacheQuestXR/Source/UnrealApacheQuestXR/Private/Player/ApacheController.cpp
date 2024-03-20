// Copyright Sherwin Espela 2024. All Rights Reserved.


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
	Super::SetupInputComponent();

	EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AApacheController::Move);
	EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &AApacheController::Rotate);
}

void AApacheController::Move(const FInputActionValue& Value)
{
	if (VRPlayer == nullptr) return;
	VRPlayer->MoveChopper(Value);
}

void AApacheController::Rotate(const FInputActionValue& Value)
{
	if (VRPlayer == nullptr) return;
	VRPlayer->RotateChopper(Value);
}
