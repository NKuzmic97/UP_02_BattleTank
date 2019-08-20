#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	void Tick(float) override;
protected:
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 6000;
private:
	virtual void SetPawn(APawn* InPawn) override;
	
	UFUNCTION()
	void OnPossessedTankDeath();
};
