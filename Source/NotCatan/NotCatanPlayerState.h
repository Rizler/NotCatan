// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NotCatanPlayerState.generated.h"

/**
 *
 */
UCLASS()
class NOTCATAN_API ANotCatanPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure)
	FString getName() const;
	UFUNCTION()
	void setName(const FString& name);
	UFUNCTION(BlueprintPure)
	uint8 getVictoryPoints() const;
	UFUNCTION()
	void setVictoryPoints(uint8 victoryPoints);
	UFUNCTION(BlueprintPure)
	uint8 getResourcesCount() const;
	UFUNCTION(BlueprintPure)
	uint8 getDevelopmentCardsCount() const;
	UFUNCTION(BlueprintPure)
	FColor getColor() const;
	UFUNCTION()
	void setColor(const FColor& color);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Replication methods - called on client
	UFUNCTION()
	virtual void onRep_victoryPoints();

	UFUNCTION()
	virtual void onRep_color();

	UFUNCTION()
	virtual void onRep_name();

protected:
	UFUNCTION(BlueprintNativeEvent)
	void updateUi();

	
private:
	UPROPERTY(ReplicatedUsing = onRep_name)
	FString m_name;
	UPROPERTY(ReplicatedUsing = onRep_victoryPoints)
	uint8 m_victoryPoints;
	UPROPERTY(Replicated)
	uint8 m_resourcesCount;
	UPROPERTY(Replicated)
	uint8 m_developmentCardsCount;
	UPROPERTY(ReplicatedUsing = onRep_color)
	FColor m_color;
};