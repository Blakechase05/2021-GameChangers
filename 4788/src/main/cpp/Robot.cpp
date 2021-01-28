#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;

// Robot Logiccd
void Robot::RobotInit() {
	// Init the controllers
	ControlMap::InitsmartControllerGroup(robotMap.contGroup);

	intake = new Intake(robotMap.intakeSystem.intakeGearbox, robotMap.intakeSystem.intakeDown);

	intake->SetDefault(std::make_shared<IntakeManualStrategy>("Intake Manual", *intake, robotMap.contGroup));

	StrategyController::Register(intake);
}

void Robot::RobotPeriodic() {
	currentTimeStamp = Timer::GetFPGATimestamp();
	dt = currentTimeStamp - lastTimeStamp;

	// Update our controllers and strategy
	StrategyController::Update(dt);
	intake->update(dt);
	NTProvider::Update();

	lastTimeStamp = currentTimeStamp;
}

// Dissabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {
	Schedule(std::make_shared<IntakeAutoStrategy>("Intake Auto", *intake, robotMap.contGroup), true);
}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {
	Schedule(intake->GetDefaultStrategy(), true); // Use default manual strategy for intake
}
void Robot::TeleopPeriodic() {}

// Test Logic4
void Robot::TestInit() {}
void Robot::TestPeriodic() {}