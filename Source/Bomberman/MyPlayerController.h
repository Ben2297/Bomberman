#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"
#include "MyPlayer.h"
#include "MyPlayerController.generated.h"

UCLASS()
class BOMBERMAN_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

private:
	AMyPlayer* SecondPlayer;

	UFUNCTION()
		void MoveForward(float Value);

	UFUNCTION()
		void MoveRight(float Value);

	UFUNCTION()
		void PlaceBomb();

	UFUNCTION()
		void MoveForward_2(float Value);

	UFUNCTION()
		void MoveRight_2(float Value);

	UFUNCTION()
		void PlaceBomb_2();
};
