#include "Robot.h"

using namespace frc;
using namespace wml;

using hand = frc::XboxController::JoystickHand;

double currentTime;
double lastTimeStamp;
double dt; //stands for delta time 

//add other variables here
//double sparkSpeed;
double dbLeftspeed;
double dbRightspeed;
double constexpr deadzone = 0.1;

// Robot Logic
void Robot::RobotInit() {
	//init controllers 
	xbox = new frc::XboxController(0);

	//Motor examples 
	//	_sparkMotor = new frc::Spark(0);
	_talonMotorL = new wml::TalonSrx(1);
	_talonMotorR = new wml::TalonSrx(2);
	_victorMotorL = new wml::VictorSpx(8);
	_victorMotorR = new wml::VictorSpx(9);

	//	_sparkMotor->SetInverted(true);
	_talonMotorL->SetInverted(true);
	_talonMotorR->SetInverted(false);
	_victorMotorL->SetInverted(true);
	_victorMotorR->SetInverted(false);
}

void Robot::RobotPeriodic() {}

// Disabled Robot Logic
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

// Auto Robot Logic
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

// Manual Robot Logic
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
	currentTime = Timer::GetFPGATimestamp();
	dt = currentTime - lastTimeStamp;

	//motor examples
	//	sparkSpeed = xbox->GetY(hand::kLeftHand);
	//	_sparkMotor->Set(sparkSpeed);


	dbLeftspeed = xbox->GetY(hand::kLeftHand); //Sets the speed of the left db motor to the xbox left stick
	if (abs(dbLeftspeed) >= deadzone) {
		_talonMotorL->Set(dbLeftspeed);
		_victorMotorL->Set(dbLeftspeed);
	} else {
		_talonMotorL->Set(0);
		_victorMotorL->Set(0);
	}

	dbRightspeed = xbox->GetY(hand::kRightHand); //Sets the speed of the right db motor to the xbox left stick
	if (abs(dbRightspeed) >= deadzone) {
		_talonMotorR->Set(dbRightspeed);
		_victorMotorR->Set(dbRightspeed);
	} else {
		_talonMotorR->Set(0);
		_victorMotorR->Set(0);
	}
	

	// ^ the equivalent using a conditional statement 
	//talonSpeed = xbox->GetTriggerAxis(hand::kRightHand) > deadzone ? xbox->GetTriggerAxis(hand::kRightHand) : 0; _talonMotor->Set(talonSpeed);


	//	if(xbox->GetXButton()) {
	//		_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
	//	} else {
	//		_solenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
	//	}

	//	_compressor.Update(dt);
	//	_solenoid.Update(dt);

	//	if (_solenoid.IsDone()) _solenoid.Stop();
	lastTimeStamp = currentTime;
}

// Test Logic
void Robot::TestInit() {}
void Robot::TestPeriodic() {}
