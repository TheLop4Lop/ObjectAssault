// Fill out your copyright notice in the Description page of Project Settings.


#include "MovablePlatform.h"

// Sets default values
AMovablePlatform::AMovablePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovablePlatform::BeginPlay()
{
	Super::BeginPlay();
	OriginalVector = GetActorLocation();
	
}

// Called every frame
void AMovablePlatform::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
}

void AMovablePlatform::MovePlatform(float &Delta_Time)
{
	FVector LocalVector = GetActorLocation();

	if(FlagBackwardCheck == false){
		LocalVector += (VelocityVector * Delta_Time);
		SetActorLocation(LocalVector);
		if(Distance >= MaxValueDistance){//posible modificación de posición
			OriginalVector = GetActorLocation();
			FlagBackwardCheck = true;
		}
	}else{
		LocalVector -= (VelocityVector * Delta_Time);
		SetActorLocation(LocalVector);
		if(Distance >= MaxValueDistance){
			OriginalVector = GetActorLocation();
			FlagBackwardCheck = false;
		}
	}
	
	Distance = FVector::Dist(OriginalVector, LocalVector);
}

void AMovablePlatform::RotatePlatform(float &Delta_Time)
{
	AddActorLocalRotation(VelocityRotation * Delta_Time);
}