// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "SnakeBase.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) 
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake)) 
		{
			Snake->AddSnakeElement();
			this->Destroy();
			this->SpawnFood();
		}
	}
}

void AFood::SpawnFood()
{
	// x in [-470; 470]
	// y in [-470; 470]

	float min_x_y = -470.f;
	float max_x_y = 470.f;

	float spawn_z = 40.f;
	float spawn_x = FMath::FRandRange(min_x_y, max_x_y);
	float spawn_y = FMath::FRandRange(min_x_y, max_x_y);

	FVector NewFoodLocation(spawn_x, spawn_y, spawn_z);
	FTransform FoodTransform(NewFoodLocation);
	AFood* SpawnedFood = GetWorld()->SpawnActor<AFood>(FoodElements, FoodTransform);
	//// AFood* Food_Elem = 
}

