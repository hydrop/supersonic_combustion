#include <iostream>
#include "src/base/Case/Case.h"
#include "src/utility/CaseSettings.h"

int main(int argc, char** argv){
	SupersonicCombustion::CaseSettings runCaseSettings = SupersonicCombustion::CaseSettings(argc, argv);
	SupersonicCombustion::Case runCase = SupersonicCombustion::Case(runCaseSettings);
    runCase.prepare();
    runCase.solve();
    runCase.finishing();
    std::cout << "Program terminated.\n";
    return 0;
}
