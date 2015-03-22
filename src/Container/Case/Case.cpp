#include "Case.h"

// constructor & destructor
comPcomB::Case::Case(CaseSettings& runCaseSettings){
	if (runCaseSettings.info.get("simpledomain",0)){
	domains = new SimpleDomain;
	domainCount = 1;
	}
}

comPcomB::Case::~Case(void){
	if (domainCount==1) delete domains;
	else delete[] domains;
}

void comPcomB::Case::setCaseName(std::string name){
	caseName = name;
}

void comPcomB::Case::prepare(void){
//   alloc_domain();
//   generate_geometry();
//   generate_initial_condition());
	int i, j, idx;

	// When domain points to a SimpleCase object
	comPcomB::SimpleDomain* sDomain = dynamic_cast<comPcomB::SimpleDomain*>(domains);
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

void comPcomB::Case::solve(void){
	int i, j, iter, idx;
	int n,e,w,s;
	real* t;

	// When domain points to a SimpleCase object
	comPcomB::SimpleDomain* sDomain = dynamic_cast<comPcomB::SimpleDomain*>(domains);
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

void comPcomB::Case::finishing(void){
	comPcomB::SimpleDomain* sDomain = dynamic_cast<comPcomB::SimpleDomain*>(domains);
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

