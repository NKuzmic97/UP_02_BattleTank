// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Tank.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay() {
	Super::BeginPlay();
}

void ATank::Fire() {
	if (!ensure(Barrel)) return;
	bool bisReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSecond;
	if (bisReloaded) {
		// Spawn a projectile at the socket location at the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(4000.f);
		LastFireTime = FPlatformTime::Seconds();
	}
}