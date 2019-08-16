// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
private:	
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSecond = 3;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;
	double LastFireTime = 0;
	UTankBarrel* Barrel = nullptr; // TODO Remove
public:
	UFUNCTION(BlueprintCallable)
	void Fire();
};
