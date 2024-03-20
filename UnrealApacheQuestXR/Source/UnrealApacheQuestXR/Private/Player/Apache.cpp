// Copyright Sherwin Espela 2024. All Rights Reserved.

#include "Player/Apache.h"

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

