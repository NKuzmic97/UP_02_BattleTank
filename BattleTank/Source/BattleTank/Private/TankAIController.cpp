#include "Public/TankAIController.h"
#include "Tank.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) UE_LOG(LogTemp, Warning, TEXT("AIController: Player Tank: %s"), *PlayerTank->GetName())
	else UE_LOG(LogTemp,Error,TEXT("AIController:: No Player Tank is found!"))
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		GetPossessedByAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		// TODO Move towards the players
		// Aim towards the player
		// Fire if ready
	}
}

ATank* ATankAIController::GetPossessedByAITank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
