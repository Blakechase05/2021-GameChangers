/**
 * main/include/strategies/IntakeStrategies.h
 */

#include "Intake.h" // Our intake in main/include/Intake.h
#include "strategy/Strategy.h" // in WML

using Controllers = wml::controllers::SmartControllerGroup;

/**
 * Main class for the strategies of the Intake (Main do this then that logic for manual control)
 */
class IntakeManualStrategy : public wml::Strategy {
 public:

	/**
	 * Contructor for passing in our intake and controllers
	 */
	IntakeManualStrategy(std::string name, Intake &intake, Controllers &contGroup);

	/**
	 * On Update logic. Auto called from strategy (hence override). Pass in delta time
	 */
	void OnUpdate(double dt) override;

 private:
	Intake &_intake;
	Controllers &_contGroup;
};

/**
 * Main class for the strategies of the Intake (Main do this then that logic for auto control)
 */
class IntakeAutoStrategy : public wml::Strategy {
 public:

	/**
	 * Contructor for passing in intaje and controllers for auto. (Might want to pass in sensors aswell)
	 */
	IntakeAutoStrategy(std::string name, Intake &intake, Controllers &contGroup);

	/**
	 * On Update logic. Auto called from strategy controller (hence override). Pass in delta time 
	 */
	void OnUpdate(double dt) override;

	Intake &_intake;
	Controllers &_contGroup;
};