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
private:
	// How close can the AI tank get
	float AcceptanceRadius = 3000;
};
