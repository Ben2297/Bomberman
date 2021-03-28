#include "MyPowerUp.h"
#include "UObject/ConstructorHelpers.h"

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
	BoxComponent->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));
	BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));

	// Adds a static mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	MeshComponent->SetupAttachment(GetRootComponent());
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
	MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -48.f));

	// Sets static mesh material
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
	MaterialReference = MaterialAsset.Object;
	if (MaterialAsset.Succeeded())
	{
		MeshComponent->SetMaterial(0, MaterialReference);
	}
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
			Destroy();
		}
	}
}