// Copyright Echo Team 2017

#include "PestControl.h"
#include "PestBase.h"


// Sets default values
APestBase::APestBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APestBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APestBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FVector APestBase::GetNavigationDirection()
{
	FVector DirectVector = NavigationTarget - GetActorLocation();
	FVector Indication = DirectVector.GetUnsafeNormal();
	FVector Direction = Indication - FVector::DotProduct(NavigationNormal, Indication) * NavigationNormal;

	return Direction.GetUnsafeNormal();
}

float APestBase::GetNavigationDistance()
{
	return FVector::Dist(NavigationTarget, GetActorLocation());
}

float APestBase::GetNavigationRange(float minimum, float maximum)
{
	return FMath::Clamp((GetNavigationDistance() - minimum) / (maximum - minimum), 0.0f, 1.0f);
}


bool APestBase::GetWeightedAverage(TArray<AActor*> actors, float minimum, float maximum, FVector& average)
{
	average.Set(0.0f, 0.0f, 0.0f);

	float totalWeight = 0.0f;

	for(AActor* actor : actors) {
		float Distance = FVector::Dist(actor->GetActorLocation(), GetActorLocation());

		float weight = 1.0f - FMath::Clamp((Distance - minimum) / (maximum - minimum), 0.0f, 1.0f);

		average += actor->GetActorLocation() * weight;

		totalWeight += weight;
	}

	if(totalWeight > 0.0f) {
		average /= totalWeight;

		return true;
	}
	else {
		return false;
	}
}