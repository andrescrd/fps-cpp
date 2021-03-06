// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class FPSCPP_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

protected:
	// virtual void BeginPlay() override;

public:
	FTimerHandle shootTimerHandle;

	UPROPERTY(VisibleAnywhere)	class UCameraComponent *cam;
	UPROPERTY(VisibleAnywhere)	class USkeletalMeshComponent *arms;
	UPROPERTY(VisibleAnywhere)	class USkeletalMeshComponent *gun;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)	bool firing;
	UPROPERTY(EditAnywhere)	float rotationSpeed = 45;
	UPROPERTY(EditAnywhere)	float baseDamage = 100;
	UPROPERTY(EditAnywhere)	TMap<FName, float> damages;

	// virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);
	void RotateYaw(float value);
	void RotatePitch(float value);
	void StartJump();
	void StopJump();
	void StartShoot();
	void ShootTimer();
	void StopShoot();
};
