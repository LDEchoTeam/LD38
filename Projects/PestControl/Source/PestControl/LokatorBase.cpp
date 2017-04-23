// Copyright Echo Team 2017

#include "PestControl.h"
#include "LokatorBase.h"


// Sets default values
ALokatorBase::ALokatorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALokatorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALokatorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Navigate(DeltaTime);

}

void ALokatorBase::Navigate(float DeltaTime)
{

}

