// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

UTankBarrel::UTankBarrel() {
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

