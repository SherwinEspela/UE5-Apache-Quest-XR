// Copyright Sherwin Espela 2024. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Apache.generated.h"

class USkeletalMeshComponent;
struct FInputActionValue;

// TODO: Delete Later

UCLASS()
class UNREALAPACHEQUESTXR_API AApache : public AActor
{
	GENERATED_BODY()
	
public:	
	AApache();
	virtual void Tick(float DeltaTime) override;

	void Move(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Chopper Player")
	TObjectPtr<USkeletalMeshComponent> ChopperMesh;

};
