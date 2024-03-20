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

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Chopper Mesh")
	USkeletalMeshComponent* ChopperMesh;
};
