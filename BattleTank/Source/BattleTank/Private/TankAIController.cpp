// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledAITank = GetPossessedByAITank();
	if(ControlledAITank) UE_LOG(LogTemp,Warning,TEXT("AI Tank: %s"),*ControlledAITank->GetName())
	else UE_LOG(LogTemp,Error,TEXT("No tank is possessed by AI!"))
}

ATank* ATankAIController::GetPossessedByAITank() const {
	return Cast<ATank>(GetPawn());
}
