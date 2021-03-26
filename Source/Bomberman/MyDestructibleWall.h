#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};