#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Public/Tank.h"
#include "TankPlayerController.generated.h" // Must be last include

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	void Tick(float) override;
private:
	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333f;
	ATank* GetControlledTank() const;
	// Start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector&) const;
	bool GetLookDirection(FVector2D, FVector&) const;
};
