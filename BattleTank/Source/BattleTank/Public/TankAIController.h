#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Public/Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;

private:
	ATank* GetPossessedByAITank() const;
	ATank* GetPlayerTank() const;
};
