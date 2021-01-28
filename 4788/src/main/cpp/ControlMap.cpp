#include "ControlMap.h"

using namespace wml;
using namespace wml::controllers;

void ControlMap::InitsmartControllerGroup(SmartControllerGroup &contGroup) {
	// Remap Here (map POV buttons to names etc)
}


// ------------------ Values ------------------


// Controller Ports
const int ControlMap::Xbox1Port = 0;
const int ControlMap::Xbox2Port = 1;

// Deadzones
const double ControlMap::XboxDeadzone = 0.1;
const double ControlMap::TriggerDeadzone = 0.15;

// PCMs
const int ControlMap::PCModule = 1;

// Intake
const int ControlMap::intakePort = 99;
const int ControlMap::intakeSolenoidPort1 = 0;
const int ControlMap::intakeSolenoidPort2 = 1;
const int ControlMap::intakeEncoderTicks = 2048;
const double ControlMap::IntakeAutoSpeed = 0.3;

// ------------------ Controls ------------------

// Intake
const tAxis ControlMap::Intake{ Driver, XboxController::kRightThrottle };
const tAxis ControlMap::Outake{ Driver, XboxController::kLeftThrottle };
const tButton ControlMap::DeployIntake{ Driver, XboxController::kA };