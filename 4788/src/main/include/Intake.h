/**
 * main/include/Intake.h
 */

#pragma once

#include "strategy/StrategySystem.h" // In WML (Note strategy system. NOT STRATEGY.H. Strategy.h is for the actual strategy in include/strategy/IntakeStrategies.h)
#include "RobotMap.h" // Our robotmap


/**
 * Declared states the intake can be in
 */
enum class IntakeState {
	STOWED, // Up, motor off
	DEPLOYED, // Down, motor on (variable speed)
};

/**
 * Main intake class
 */
class Intake : public wml::StrategySystem {
 public:

	/**
	 * Constructor to pass in gearbox andsolenoid to Intake class
	 */
	Intake(wml::Gearbox &intakeGearbox, wml::actuators::DoubleSolenoid &intakeSolenoid);


	/**
	 * Set intake state and power, (this then modifies the intakeUpdate() state)
	 */
	void setIntake(const IntakeState st, double power = 0);

	/**
	 * Looping update for intake
	 */	
	void updateIntake(double dt);

	/**
	 * Update (master looping update for Intake)
	 */
	void update(double dt);

 private:
	// Class controllable gearboxes
	wml::Gearbox &_intakeGearbox;
	wml::actuators::DoubleSolenoid &_intakeSolenoid;

	// States
	IntakeState _intakeState{ IntakeState::STOWED }; // Default state is stowed. (Robot switches on and goes to this state)

	// intake motor power
	double _power;
};