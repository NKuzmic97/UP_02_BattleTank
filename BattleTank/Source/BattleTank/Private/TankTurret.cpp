#include "TankTurret.h"

UTankTurret::UTankTurret() {
	// Workaround for blueprint bug forgetting static mesh when this class is recompiled
	// https://issues.unrealengine.com/issue/UE-63298
	if (!GetStaticMesh()) {
		UE_LOG(LogTemp, Warning, TEXT("Turret loading mesh at runtime."));
		UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Tank/tank_fbx_Turret.fbx"));
		SetStaticMesh(Mesh ? Mesh : nullptr);
	}
}

void UTankTurret::TurnAzimuth(float RelativeSpeed) {
	// Move the turret right amount this frame
	// Given a max turn speed speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto TurnChange = RelativeSpeed * MaxAzimuthDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto RawNewTurn = RelativeRotation.Yaw + TurnChange;
	SetRelativeRotation(FRotator(0,RawNewTurn, 0));
}