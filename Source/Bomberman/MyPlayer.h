#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawnMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "MyBomb.h"
#include <vector>
#include "MyPlayer.generated.h"

UCLASS()
class BOMBERMAN_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

	// Sphere collision volume
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* SphereComponent;

	// Static mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TSubclassOf<class AMyBomb> Bomb;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void IncreaseBombBlast();

	void MoreBombs();

	void BoostSpeed();

	void RemoteBombs();

	UFUNCTION()
		void MoveForward(float Value);

	UFUNCTION()
		void MoveRight(float Value);

	UFUNCTION()
		void PlaceBomb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Bomb's initial distance from player
	static const int BOMB_INIT_DIST = 20;

	int maxBombs;
	int currentBombs;
	std::vector<AMyBomb*> MyBombs;

	bool movingForward;
	bool movingRight;

	bool bigBlast;

	float speedMultiplier;


	class UMyPawnMovementComponent* MovementComponent;

	virtual UMyPawnMovementComponent* GetMovementComponent() const override;
};