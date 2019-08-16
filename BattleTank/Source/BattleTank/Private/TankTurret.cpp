#include "TankTurret.h"

UTankTurret::UTankTurret() {
}

void UTankTurret::TurnAzimuth(float RelativeSpeed) {
	// Move the turret right amount this frame
	// Given a max turn speed speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto TurnChange = RelativeSpeed * MaxAzimuthDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto RawNewTurn = RelativeRotation.GetNormalized().Yaw + TurnChange;
	SetRelativeRotation(FRotator(0,RawNewTurn, 0));
}