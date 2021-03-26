#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "ParticleDefinitions.h"
#include "Engine/EngineTypes.h"
#include "MyDestructibleWall.h"
#include <vector>
#include "MyBomb.generated.h"

UCLASS()
class BOMBERMAN_API AMyBomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBomb();

	// Collision box
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* SphereComponent;

	// Static mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;

	// Mesh material
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UMaterialInterface* MaterialReference;

	// Particle system
	UPROPERTY(EditDefaultsOnly)
		UParticleSystem* ParticleComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Timer handle
	FTimerHandle FuseTimerHandle;

	std::vector<AMyDestructibleWall*> WallsToDestroy;

	// Function to call upon explosion
	UFUNCTION()
		void OnExplode();
};