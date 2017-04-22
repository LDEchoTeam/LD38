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
	FVector Direction = Indication - FVector::DotProduct(NavigationNormal, Indication);

	return Direction;
}