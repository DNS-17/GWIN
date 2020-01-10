// Fill out your copyright notice in the Description page of Project Settings.


#include "GWCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"

// Sets default values
AGWCharacterBase::AGWCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("PlayerMesh");
	MeshComp->SetupAttachment(RootComponent);

	BaseTurnRate = 45.0f;
	BaseLookUpAtRate = 45.0f;
}

void AGWCharacterBase::MoveForward(float Value)
{
	if (Controller && Value != 0.0f) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AGWCharacterBase::MoveRight(float Value)
{
	if (Controller && Value != 0.0f) {
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AGWCharacterBase::TurnAtRate(float Value)
{
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGWCharacterBase::LookUpAtRate(float Value)
{
	AddControllerPitchInput(Value * BaseLookUpAtRate * GetWorld()->GetDeltaSeconds());
}

// Called to bind functionality to input
void AGWCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Action binds
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Moving binds
	PlayerInputComponent->BindAxis("MoveForward", this, &AGWCharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGWCharacterBase::MoveRight);

	// Rotation binds
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("TurnRate", this, &AGWCharacterBase::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpAtRate", this, &AGWCharacterBase::LookUpAtRate);
}

