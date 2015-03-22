
#include <iostream>
#include "src/Container/Case/Case.h"
#include "src/utility/CaseSettings.h"

int main(int argc, char** argv){
	// From arguments, get filename which contains case settings.
	comPcomB::CaseSettings runCaseSettings = comPcomB::CaseSettings(argc, argv);

	// Using imported case settings, make a runCase class instance.
	comPcomB::Case runCase = comPcomB::Case(runCaseSettings);

	// Prepare for simulation loop
	runCase.prepare();

	// Run solver
    runCase.solve();

    // Show result of the simulation and clean up
    runCase.finishing();

    std::cout << "Program terminated.\n";
    return 0;
}

