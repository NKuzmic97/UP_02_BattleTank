#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent), hidecategories=("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void TurnAzimuth(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere,category="Setup")
	float MaxAzimuthDegreesPerSecond = 10.f;
};
