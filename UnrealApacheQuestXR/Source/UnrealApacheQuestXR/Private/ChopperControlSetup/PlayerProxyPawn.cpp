// Copyright Sherwin Espela 2024. All Rights Reserved.


#include "ChopperControlSetup/PlayerProxyPawn.h"

// Sets default values
APlayerProxyPawn::APlayerProxyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerProxyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerProxyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerProxyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

