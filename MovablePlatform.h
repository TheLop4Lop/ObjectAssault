// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovablePlatform.generated.h"

UCLASS()
class OBJECTASSAULT_API AMovablePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovablePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector OriginalVector;
	
	//Variables
	UPROPERTY(EditAnywhere, Category = "Movement")
	bool FlagBackwardCheck = false;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector VelocityVector = FVector(250,0,0);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxValueDistance = 100;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	float Distance;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator VelocityRotation;

	void MovePlatform(float &Delta_Time);
	void RotatePlatform(float &Delta_time);

};
