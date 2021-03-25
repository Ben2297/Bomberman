#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawnMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "MyBomb.h"
#include "MyPlayer.generated.h"

UCLASS()
class BOMBERMAN_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

	// Collision sphere
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* SphereComponent;

	// Static mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TSubclassOf<class AActor> Bomb;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Bomb's initial distance from player
	static const int BOMB_INIT_DIST = 30;

	int maxBombs;
	int currentBombs;
	AMyBomb* MyBomb;

	bool movingForward;
	bool movingRight;

	UFUNCTION()
		void MoveForward(float Value);

	UFUNCTION()
		void MoveRight(float Value);

	UFUNCTION()
		void PlaceBomb();

	class UMyPawnMovementComponent* MovementComponent;

	virtual UMyPawnMovementComponent* GetMovementComponent() const override;
};