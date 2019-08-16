#include "Public/TankAIController.h"
#include "Tank.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
// Depends on TankMovementComponent via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (ensure(PlayerTank)) {
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius in cm

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());	
		// Fire if ready
		ControlledTank->Fire(); // TODO limit firing rate
	}
}