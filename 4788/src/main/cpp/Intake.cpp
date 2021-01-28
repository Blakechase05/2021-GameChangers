/**
 * main/cpp/Intake.cpp
 */
#include "Intake.h"

/**
 * Constructor logic (binds our private `_intake` to the `intake` being passed in)
 */
Intake::Intake(wml::Gearbox &intakeGearbox, wml::actuators::DoubleSolenoid &intakeSolenoid) : _intakeGearbox(intakeGearbox), _intakeSolenoid(intakeSolenoid) {}


/**
 * Set intake state and power
 */
void Intake::setIntake(const IntakeState st, double power) {
	_intakeState = st;
	_power = power;
}

/**
 * State update logic for Intake
 */
void Intake::updateIntake(double dt) {
	double voltage = 0; // Voltage to set the gearbox to

	switch(_intakeState) {

		case IntakeState::STOWED: // Stowed Control
			voltage = 0;
			_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kReverse);
			break;

		case IntakeState::DEPLOYED: // Deployed Control
			voltage = 12 * _power; // private class _power modified by strategies/IntakeStrategies
			_intakeSolenoid.SetTarget(wml::actuators::BinaryActuatorState::kForward);
			break;
	}

	_intakeGearbox.transmission->SetVoltage(voltage);
	_intakeSolenoid.Update(dt);
}

/**
 * Master update for Intake
 */
void Intake::update(double dt) {
	updateIntake(dt);
}