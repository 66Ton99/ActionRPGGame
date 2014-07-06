// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "../Types/ARStructTypes.h"

#include "../Types/ARAttributeTypes.h"
#include "ARTrailCue.generated.h"

UCLASS(hidecategories = (Object, LOD, Lighting, Transform, Sockets, TextureStreaming), editinlinenew, meta = (BlueprintSpawnableComponent))
class UARTrailCue : public UActorComponent
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trail Effect")
		UParticleSystem* TrailFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trail Effect")
		FName StartSocket;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trail Effect")
		float TrailSpeed2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trail Effect")
		FName TrailSpeedParam2;

	UPROPERTY(ReplicatedUsing = OnRep_Hit, BlueprintReadWrite, Category="Hit Info")
		FHitInfo HitInfo;
	UFUNCTION()
		void OnRep_Hit();
	void SimulateHitOnClients(FVector Origin, FVector Location, FName StartSocket);
};


