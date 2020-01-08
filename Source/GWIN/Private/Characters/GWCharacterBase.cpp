// Fill out your copyright notice in the Description page of Project Settings.


#include "GWCharacterBase.h"

// Sets default values
AGWCharacterBase::AGWCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGWCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void AGWCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

