#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MyIncreaseBombBlast.h"
#include "MyMoreBombs.h"
#include "MySpeedBoost.h"
#include "MyDestructibleWall.generated.h"

UCLASS()
class BOMBERMAN_API AMyDestructibleWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyDestructibleWall();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Static mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TSubclassOf<class AMyIncreaseBombBlast> increaseBombBlast;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TSubclassOf<class AMyMoreBombs> moreBombs;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TSubclassOf<class AMySpeedBoost> speedBoost;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool dropPowerUp;

	UFUNCTION()
		void WhenDestroyed(AActor* Act);
};