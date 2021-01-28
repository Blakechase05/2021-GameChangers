/**
 * main/cpp/strategies/IntakeStrategies.cpp
 */
#include "strategies/IntakeStrategies.h"

/**
 * Intake manual strategy Constructor
 */
IntakeManualStrategy::IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {}

/**
 * Intake manual strategy logic (auto called by the strategy controller)
 */
void IntakeManualStrategy::OnUpdate(double dt) {
	double powerIn = fabs(_contGroup.Get(ControlMap::Intake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Intake) : 0;
	double powerOut = fabs(_contGroup.Get(ControlMap::Outake)) > ControlMap::TriggerDeadzone ? _contGroup.Get(ControlMap::Outake) : 0;

	if (_contGroup.Get(ControlMap::DeployIntake, wml::controllers::Controller::ONFALL)) {
		_intake.setIntake(IntakeState::DEPLOYED, powerIn - powerOut);
	} else {
		_intake.setIntake(IntakeState::STOWED);
	}
}

/**
 * Intake auto strategy constructor
 */
IntakeAutoStrategy::IntakeAutoStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {}

/**
 * Auto on update logic. (Called by strategy controller. In this strategy we just have the intake always on)
 */
void IntakeAutoStrategy::OnUpdate(double dt) {
	double powerIn = ControlMap::IntakeAutoSpeed;

	_intake.setIntake(IntakeState::DEPLOYED, powerIn);
}