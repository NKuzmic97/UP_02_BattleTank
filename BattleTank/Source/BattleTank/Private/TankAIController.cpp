#include "Public/TankAIController.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


// Depends on TankMovementComponent via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(PlayerTank && GetPawn())) return;

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius in cm
	// Aim towards the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	// Fire if ready

	if(AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
		AimingComponent->Fire(); // TODO limit firing rate
}