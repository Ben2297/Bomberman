#include "MyBomb.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyBomb::AMyBomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adds a static mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	MeshComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
		MeshComponent->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Steel.M_Metal_Steel'"));
	MaterialReference = MaterialAsset.Object;
	if (MaterialAsset.Succeeded())
	{
		MeshComponent->SetMaterial(0, MaterialReference);
	}
}

// Called when the game starts or when spawned
void AMyBomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}