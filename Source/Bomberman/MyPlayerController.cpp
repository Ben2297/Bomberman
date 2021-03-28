#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"

AMyPlayerController::AMyPlayerController()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMyPlayer::StaticClass(), FoundActors);

	for (AActor* TempActor : FoundActors)
	{
		AMyPlayer* MyActor = Cast<AMyPlayer>(TempActor);

		if (MyActor != nullptr && MyActor != Cast<AMyPlayer>(this->GetPawn()))
		{
			SecondPlayer = MyActor;
		}
	}
}

// Called to bind functionality to input
void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AMyPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
	InputComponent->BindAction("PlaceBomb", IE_Pressed, this, &AMyPlayerController::PlaceBomb);

	InputComponent->BindAxis("MoveForward_2", this, &AMyPlayerController::MoveForward_2);
	InputComponent->BindAxis("MoveRight_2", this, &AMyPlayerController::MoveRight_2);
	InputComponent->BindAction("PlaceBomb_2", IE_Pressed, this, &AMyPlayerController::PlaceBomb_2);
}

void AMyPlayerController::MoveForward(float Value)
{
	auto TempPawn = Cast<AMyPlayer>(this->GetPawn());
	if (TempPawn)
	{
		TempPawn->MoveForward(Value);
	}
}

void AMyPlayerController::MoveRight(float Value)
{
	auto TempPawn = Cast<AMyPlayer>(this->GetPawn());
	if (TempPawn)
	{
		TempPawn->MoveRight(Value);
	}
}

void AMyPlayerController::PlaceBomb()
{
	auto TempPawn = Cast<AMyPlayer>(this->GetPawn());
	if (TempPawn)
	{
		TempPawn->PlaceBomb();
	}
}

void AMyPlayerController::MoveForward_2(float Value)
{
	SecondPlayer->MoveForward(Value);
}

void AMyPlayerController::MoveRight_2(float Value)
{
	SecondPlayer->MoveRight(Value);
}

void AMyPlayerController::PlaceBomb_2()
{
	SecondPlayer->PlaceBomb();
}
