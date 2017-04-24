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

}

FVector ALokatorBase::GetIntermediateNavigationNormal(float NavigationSpeed, float DeltaTime)
{
	FVector Radial = GetActorLocation().GetUnsafeNormal();

	float Angle = NavigationSpeed * DeltaTime;

	FVector Axis = FVector::CrossProduct(GetActorLocation(), NavigationTarget).GetUnsafeNormal();

	return Radial.RotateAngleAxis(Angle, Axis);

}

FVector ALokatorBase::GetIntermediateNavigationTangent(FVector IntermediateNormal, float RotationSpeed, float DeltaTime)
{
	FVector DirectVector = NavigationTarget - GetActorLocation();
	FVector Indication = DirectVector.GetUnsafeNormal();
	FVector Target = Indication - FVector::DotProduct(IntermediateNormal, Indication) * IntermediateNormal;

	float Angle = RotationSpeed * DeltaTime;

	FQuat Rotation = FQuat::FindBetweenNormals(GetActorUpVector(), IntermediateNormal);

	FVector Tangent = Rotation.RotateVector(GetActorForwardVector());

	FVector Axis = FVector::CrossProduct(Tangent, Target.GetUnsafeNormal());

	return Tangent.RotateAngleAxis(Angle, Axis);

}

