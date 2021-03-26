#include "MyBomb.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyBomb::AMyBomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	// Adds a static mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	SetRootComponent(MeshComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
		MeshComponent->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
	}

	// Sets static mesh material
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Steel.M_Metal_Steel'"));
	MaterialReference = MaterialAsset.Object;
	if (MaterialAsset.Succeeded())
	{
		MeshComponent->SetMaterial(0, MaterialReference);
	}

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	BoxComponent->SetupAttachment(GetRootComponent());

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	SphereComponent->SetupAttachment(GetRootComponent());
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AMyBomb::BeginPlay()
{
	Super::BeginPlay();
	
	// Sets bomb timer
	GetWorldTimerManager().SetTimer(FuseTimerHandle, this, &AMyBomb::OnExplode, 3.0f, false);
}

// Called every frame
void AMyBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when fuse time is elapsed
void AMyBomb::OnExplode()
{
	// Clears the timer
	GetWorldTimerManager().ClearTimer(FuseTimerHandle);

	if (ParticleComponent)
	{
		// Triggers the explosion effect
		UGameplayStatics::SpawnEmitterAtLocation(this, ParticleComponent, GetActorLocation(), GetActorRotation());
	}

	TArray<AActor*> Result;
	SphereComponent->GetOverlappingActors(Result, AMyDestructibleWall::StaticClass());

	for (auto& wall : Result)
	{
		wall->Destroy();
	}
	
	// Destroys the bomb
	Destroy();
}