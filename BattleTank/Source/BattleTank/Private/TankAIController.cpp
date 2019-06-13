// Copyright Nikola Novak


#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent)) { return; }
	//Aim at player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//Fire at player
	//TODO fix ControlledTank->Fire();
}
