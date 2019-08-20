#include "Public/TankAIController.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "Tank.h" // So we can implement OnDeath()
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
	if (!(PlayerTank && GetPawn())) return;

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius in cm
	// Aim towards the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	// Fire if ready

	if(AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
		AimingComponent->Fire(); // TODO limit firing rate
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) return;
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath(){
	if (!GetPawn()) return;
	GetPawn()->DetachFromControllerPendingDestroy();
}