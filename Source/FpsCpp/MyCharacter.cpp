#include "MyCharacter.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"

AMyCharacter::AMyCharacter()
{
	cam = CreateDefaultSubobject<UCameraComponent>("Camera");
	cam->bUsePawnControlRotation = true;
	cam->SetupAttachment(GetRootComponent());

	arms = CreateDefaultSubobject<USkeletalMeshComponent>("Arms");
	arms->SetupAttachment(cam);

	gun = CreateDefaultSubobject<USkeletalMeshComponent>("Gun");
	gun->SetupAttachment(arms, "GripPoint");
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::RotateYaw);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::RotatePitch);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);
}

void AMyCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void AMyCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void AMyCharacter::RotateYaw(float value)
{
	AddControllerYawInput(value * rotationSpeed * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::RotatePitch(float value)
{
	AddControllerPitchInput(value * rotationSpeed * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::StartJump()
{
	Jump();
}

void AMyCharacter::StopJump()
{
	StopJumping();
}