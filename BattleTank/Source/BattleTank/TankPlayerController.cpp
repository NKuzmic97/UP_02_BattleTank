#include "TankPlayerController.h"
#include "Tank.h"
#include "Public/TankAimingComponent.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;
	FoundAimingComponent(AimingComponent);

	auto PlayerTank = Cast<ATank>(GetPawn());
	if (PlayerTank) PlayerTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPlayerTankDeath);
}

void ATankPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!(GetPawn())) return;
	FVector HitLocation; // OUT parameter
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	if (bGotHitLocation) { // Has "side-effect", is going to line trace
		AimingComponent->AimAt(HitLocation);
	}

}
// Get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	// Deproject the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		// Linetrace along that look direction and see what we hit in range (MAX range)
		return GetLookVectorHitLocation(HitLocation, LookDirection);
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection) const {
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation,FVector LookDirection) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if(GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
		{
		HitLocation = HitResult.Location;
		return true;
		}
	HitLocation = FVector(0);
		return false; // Line trace FAILED
}

void ATankPlayerController::OnPlayerTankDeath()
{
	if (GetPawn()) {
		UE_LOG(LogTemp, Warning, TEXT("I'm dying! Arrrrrrghhhhhhhh!"));
		StartSpectatingOnly();
	}
}
