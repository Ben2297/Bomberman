#include "MyPowerUp.h"

// Sets default values
AMyPowerUp::AMyPowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	RootComponent = BoxComponent;
	BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComponent->SetGenerateOverlapEvents(true);
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyPowerUp::OnPlayerEnter);

	// Adds a static mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	MeshComponent->SetupAttachment(GetRootComponent());

	
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

void AMyPowerUp::OnPlayerEnter(UPrimitiveComponent* OverlapComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	AMyPlayer* Player = nullptr;

	if (OtherActor != nullptr)
	{
		Player = Cast<AMyPlayer>(OtherActor);
		if (Player != nullptr)
		{
			ActivatePowerUp(Player);
		}
	}
}