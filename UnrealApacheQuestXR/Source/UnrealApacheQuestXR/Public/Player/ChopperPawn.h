// Copyright Sherwin Espela 2024. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ChopperPawn.generated.h"

class USkeletalMeshComponent;
struct FInputActionValue;

UCLASS()
class UNREALAPACHEQUESTXR_API AChopperPawn : public APawn
{
	GENERATED_BODY()

public:
	AChopperPawn();

	virtual void Tick(float DeltaTime) override;

public:
	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);
	void Altitude(const FInputActionValue& Value);

	FVector GetMovementOffset(const FInputActionValue& Value) const;

public:
	//FORCEINLINE FRotator GetRotation() const { return GetActorRotation(); }

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Chopper Mesh")
	USkeletalMeshComponent* ChopperMesh;

	//Note: Apache reallife average speed is 293Km/hr
	UPROPERTY(EditAnywhere, Category = "Chopper Properties")
	float MovementSpeedMultiplier = 100.f;

	UPROPERTY(EditAnywhere, Category = "Chopper Properties")
	float YawOffsetAngle = 45.f;

	UPROPERTY(EditAnywhere, Category = "Chopper Properties")
	float AltitudeSpeedMultiplier = 70.f;
};
