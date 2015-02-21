#include "Case.h"

// constructor & destructor
SupersonicCombustion::Case::Case(CaseSettings& runCaseSettings){
	domain = new SimpleDomain();
}

SupersonicCombustion::Case::~Case(void){
	delete domain;
}

void SupersonicCombustion::Case::setCaseName(std::string name){
	caseName = name;
}

void SupersonicCombustion::Case::prepare(void){
//   alloc_domain();
//   generate_geometry();
//   generate_initial_condition());
	int i, j, idx;

	// When domain points to a SimpleCase object
	SupersonicCombustion::SimpleDomain* sDomain = dynamic_cast<SupersonicCombustion::SimpleDomain*>(domain);
	if (sDomain != 0){
		for (j = 0;j < sDomain->y;j++){
			idx = j;
			sDomain->temperature[idx] = 1.0;
		}
		for (i = 1;i < sDomain->x;i++){
			for (j = 0;j < sDomain->y;j++){
				idx = i*sDomain->x + j;
				sDomain->temperature[idx] = 0.0;
			}
		}
	}
	return;
}

void SupersonicCombustion::Case::solve(void){
	int i, j, iter, idx;
	int n,e,w,s;
	real* t;

	// When domain points to a SimpleCase object
	SupersonicCombustion::SimpleDomain* sDomain = dynamic_cast<SupersonicCombustion::SimpleDomain*>(domain);
	if (sDomain != 0){
		for (iter = 0;iter < 1000;iter++){
			for (i = 1;i < sDomain->x - 1;i++){
				for (j = 1;j < sDomain->y - 1;j++){
					real* t = sDomain->temperature;
					idx = i*sDomain->x + j;
					n = idx - sDomain->x;
					s = idx + sDomain->x;
					e = idx - 1;
					w = idx + 1;
					t[idx] = 0.25*( t[n]
					               +t[e]
					               +t[w]
					               +t[s]);
				}
			}

		}
	}
	return;
}

void SupersonicCombustion::Case::finishing(void){
	SupersonicCombustion::SimpleDomain* sDomain = dynamic_cast<SupersonicCombustion::SimpleDomain*>(domain);
	if (sDomain != 0){
		int i, j=50, idx;
		for (i = 0;i < sDomain->x;i++){
			idx = i*sDomain->x + j;
			std::cout << sDomain->temperature[idx] << std::endl;
		}
	}
	;
    return;
}

