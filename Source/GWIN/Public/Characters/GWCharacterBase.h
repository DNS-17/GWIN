// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GWCharacterBase.generated.h"

// Declarations
class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class USkeletalComponent;

UCLASS()
class GWIN_API AGWCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGWCharacterBase();

	// Camera for player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	// Static mesh / model
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
	USkeletalMeshComponent* SkeletalMeshComp;

protected:

	// Moving
	void MoveForward(float Value); 
	void MoveRight(float Value);

	// Rotating
	void TurnAtRate(float Value);
	void LookUpAtRate(float Value);

	// Special
	void InteractPressed();

	UFUNCTION(BlueprintNativeEvent) // To pewnie nie bêdzie potrzebne
	void TraceForward();
	void TraceForward_Implementation();

	// Turn speed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float BaseTurnRate;

	// Pitch turn speed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	float BaseLookUpAtRate;

	// Trace distance
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	float TraceDistance;
public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
