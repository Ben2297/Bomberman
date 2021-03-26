#include "MyPowerUp.h"

// Sets default values
AMyPowerUp::AMyPowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adds a static mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	MeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPowerUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}