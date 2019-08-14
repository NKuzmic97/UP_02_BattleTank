// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

UTankBarrel::UTankBarrel() {
	// Workaround for blueprint bug forgetting static mesh when this class is recompiled
	// https://issues.unrealengine.com/issue/UE-63298
	if (!GetStaticMesh()) {
		UE_LOG(LogTemp, Warning, TEXT("Barrel loading mesh at runtime."));
		UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Tank/tank_fbx_Barrel.fbx"));
		SetStaticMesh(Mesh ? Mesh : nullptr);
	}
}

void UTankBarrel::Elevate(float RelativeSpeed) {
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto RawNewEvelation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewEvelation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}

