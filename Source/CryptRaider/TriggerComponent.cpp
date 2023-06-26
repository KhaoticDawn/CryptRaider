// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "Engine/World.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetKeyTag() != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("Unlocked"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Relocking"));
	}
}

AActor* UTriggerComponent::GetKeyTag() const
{

	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(KeyTag))
		{
			return Actor;
		}
	}

	return nullptr;
}
