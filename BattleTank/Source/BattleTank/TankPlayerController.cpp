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
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) return;
	// Get world location if linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}