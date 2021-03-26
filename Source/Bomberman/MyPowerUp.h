#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPowerUp.generated.h"

UCLASS()
class BOMBERMAN_API AMyPowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPowerUp();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Static mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void ActivatePowerUp() PURE_VIRTUAL(AMyPowerUp::ActivatePowerUp);
};