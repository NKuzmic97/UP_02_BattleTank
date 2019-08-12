#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank) UE_LOG(LogTemp, Warning, TEXT("Player Tank: %s"), *ControlledTank->GetName())
	else UE_LOG(LogTemp, Error, TEXT("No Tank possessed!"))
}

void ATankPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) return;
	FVector HitLocation; // OUT parameter
	if (GetSightRayHitLocation(HitLocation)) { // Has "side-effect", is going to line trace
	UE_LOG(LogTemp, Error, TEXT("Hit Location: %s"),*HitLocation.ToString())
	// If it hits the landscape
		// Tell controlled tank to aim at this point
	}

}
// Get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0f);
	return true;
}
