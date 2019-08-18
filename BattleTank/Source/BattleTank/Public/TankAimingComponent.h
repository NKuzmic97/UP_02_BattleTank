// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8 {
	Reloading,
	Aiming,
	Locked,
	NoAmmo
};


// Forward declarations
class UTankBarrel; 
class UTankTurret;
class AProjectile;
// Holds barrel's properties and Elevate().
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable)
	void Fire();
	EFiringStatus GetFiringStatus() const;
	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetAmmoLeft() const;
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetProjectileBlueprint(TSubclassOf<AProjectile> Projectile);
protected:
	UPROPERTY(BlueprintReadOnly, category = "Status")
	EFiringStatus FiringStatus = EFiringStatus::Reloading;
	int Ammo = 3;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();
	FVector AimDirection;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSecond = 3;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	double LastFireTime = 0;
};

