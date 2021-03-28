#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlayer.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
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

	UFUNCTION()
		void OnPlayerEnter(UPrimitiveComponent* OverlapComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComponent,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);

	// Box collision volume
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* BoxComponent;

	// Static mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;

	// Mesh material
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UMaterialInterface* MaterialReference;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void ActivatePowerUp(AMyPlayer* Player) PURE_VIRTUAL(AMyPowerUp::ActivatePowerUp);
};