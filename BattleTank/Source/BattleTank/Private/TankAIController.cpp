// Copyright Nikola Novak


#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim at player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//Fire at player
		ControlledTank->Fire();
	}
}
