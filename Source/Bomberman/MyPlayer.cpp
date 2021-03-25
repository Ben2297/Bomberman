#include "MyPlayer.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adds a sphere collision component and sets as root
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(26.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Player"));

	// Adds a static mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	MeshComponent->SetupAttachment(RootComponent);

	// Creates a pawn movement component and sets the root as the component to update
	MovementComponent = CreateDefaultSubobject<UMyPawnMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;

	static ConstructorHelpers::FObjectFinder<UBlueprint> BombBP(TEXT("Blueprint'/Game/Blueprints/BombBP.BombBP'"));
	if (BombBP.Succeeded())
	{
		Bomb = (UClass*)BombBP.Object->GeneratedClass;
	}

	maxBombs = 1;
	currentBombs = 0;
	movingForward = movingRight = false;
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	PlayerInputComponent->BindAction("PlaceBomb", IE_Pressed, this, &AMyPlayer::PlaceBomb);
}

void AMyPlayer::MoveForward(float Value)
{
	if (Value == 0 || movingRight)
	{
		movingForward = false;
		return;
	}
	else
	{
		movingForward = true;
	}

	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->AddInputVector(FVector(1.f, 0.f, 0.f) * Value);

		// If key is being held
		if (Value != 0.f)
		{
			if (Value > 0.f)
			{
				// Moving forwards
				RootComponent->SetWorldRotation(FRotator(0.f, 0.f, 0.f) * Value);
			}
			else
			{
				// Moving backwards
				RootComponent->SetWorldRotation(FRotator(0.f, 180.f, 0.f) * Value);
			}
		}
	}
}

void AMyPlayer::MoveRight(float Value)
{
	if (Value == 0 || movingForward)
	{
		movingRight = false;
		return;
	}
	else
	{
		movingRight = true;
	}

	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->AddInputVector(FVector(0.f, 1.f, 0.f) * Value);

		// If key is being held
		if (Value != 0.f)
		{
			// Moving right/left
			RootComponent->SetWorldRotation(FRotator(0.f, 90.f, 0.f) * Value);
		}
	}
}

void AMyPlayer::PlaceBomb()
{
	std::vector<AMyBomb*>::iterator it = MyBombs.begin();
	while (it != MyBombs.end())
	{
		if (!IsValid(*it))
		{
			--currentBombs;
			it = MyBombs.erase(it);
		}
		else
		{
			++it;
		}
	}

	if (currentBombs < maxBombs)
	{
		++currentBombs;
		FVector Location = GetActorLocation() + GetActorForwardVector() * BOMB_INIT_DIST;
		Location.Z -= 13.0f;
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		MyBombs.push_back(GetWorld()->SpawnActor<AMyBomb>(Bomb, Location, Rotation, SpawnInfo));
	}
}

UMyPawnMovementComponent* AMyPlayer::GetMovementComponent() const
{
	return MovementComponent;
}