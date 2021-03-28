#include "MyDestructibleWall.h"

// Sets default values
AMyDestructibleWall::AMyDestructibleWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adds a static mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	MeshComponent->SetupAttachment(RootComponent);

	// Finds the bomb blast blueprint
		static ConstructorHelpers::FObjectFinder<UBlueprint> BombBlastBP(TEXT("Blueprint'/Game/Blueprints/Power-Ups/IncreaseBombBlastBP.IncreaseBombBlastBP'"));
	if (BombBlastBP.Succeeded())
	{
		increaseBombBlast = (UClass*)BombBlastBP.Object->GeneratedClass;
	}

	// Finds the more bombs blueprint
	static ConstructorHelpers::FObjectFinder<UBlueprint> MoreBombsBP(TEXT("Blueprint'/Game/Blueprints/Power-Ups/MoreBombsBP.MoreBombsBP'"));
	if (MoreBombsBP.Succeeded())
	{
		moreBombs = (UClass*)MoreBombsBP.Object->GeneratedClass;
	}

	// Finds the speed boost blueprint
	static ConstructorHelpers::FObjectFinder<UBlueprint> SpeedBoostBP(TEXT("Blueprint'/Game/Blueprints/Power-Ups/SpeedBoostBP.SpeedBoostBP'"));
	if (SpeedBoostBP.Succeeded())
	{
		speedBoost = (UClass*)SpeedBoostBP.Object->GeneratedClass;
	}

	OnDestroyed.AddDynamic(this, &AMyDestructibleWall::WhenDestroyed);

	dropPowerUp = false;
}

// Called when the game starts or when spawned
void AMyDestructibleWall::BeginPlay()
{
	Super::BeginPlay();
}

void AMyDestructibleWall::WhenDestroyed(AActor* Act)
{
	dropPowerUp = (FMath::RandRange(1, 100 / 30) == 1 ? true : false);
	if (dropPowerUp)
	{
		FVector Location = GetActorLocation();
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		int selectedPowerUp = FMath::RandRange(1, 3);
		switch (selectedPowerUp)
		{
		case 1:
			GetWorld()->SpawnActor<AMyIncreaseBombBlast>(increaseBombBlast, Location, Rotation, SpawnInfo);
			break;
		case 2:
			GetWorld()->SpawnActor<AMyMoreBombs>(moreBombs, Location, Rotation, SpawnInfo);
			break;
		case 3:
			GetWorld()->SpawnActor<AMySpeedBoost>(speedBoost, Location, Rotation, SpawnInfo);
			break;
		}
	}
}

// Called every frame
void AMyDestructibleWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}