// Copyright Echo Team 2017

#pragma once

#include "GameFramework/Actor.h"
#include "LokatorBase.generated.h"

UCLASS()
class PESTCONTROL_API ALokatorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALokatorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, Category="Lokator")
	FVector NavigationTarget;

private:
	void Navigate(float DeltaTime);

};
