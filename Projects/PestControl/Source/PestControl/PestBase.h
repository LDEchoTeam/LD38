// Copyright Echo Team 2017

#pragma once

#include "GameFramework/Actor.h"
#include "PestBase.generated.h"

UCLASS()
class PESTCONTROL_API APestBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APestBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, Category="Pest")
	FVector NavigationTarget;
	
	UPROPERTY(BlueprintReadWrite, Category="Pest")
	FVector NavigationNormal;

	UFUNCTION(BlueprintPure, Category="Pest")
	FVector GetNavigationDirection();

	UFUNCTION(BlueprintPure, Category="Pest")
	float GetNavigationDistance();

	UFUNCTION(BlueprintPure, Category="Pest")
	float GetNavigationRange(float minimum, float maximum);
	
};
