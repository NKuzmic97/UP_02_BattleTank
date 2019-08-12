#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) UE_LOG(LogTemp, Warning, TEXT("AIController: Player Tank: %s"), *PlayerTank->GetName())
	else UE_LOG(LogTemp,Error,TEXT("AIController:: No Player Tank is found!"))
}

ATank* ATankAIController::GetPossessedByAITank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
