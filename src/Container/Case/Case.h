/*
 * src/base/Case/Case.h
 *
 *  Created on: Dec 15, 2014
 *      Author: choiminho
 */

#ifndef SRC_BASE_CASE_CASE_H_
#define SRC_BASE_CASE_CASE_H_

#include <cstddef> // nullptr
#include <iostream> // cout
#include <string>
#include "include/define.h"
#include "src/Utility/CaseSettings.h"
#include "src/Container/Domain/Domain.h"
#include "src/Container/Domain/SimpleDomain.h"

namespace comPcomB{

class Case{
public:
	// constructor & destructor
	Case(CaseSettings&);
	virtual ~Case();

	// getter & setter
	void setCaseName(std::string);

	// member function
	virtual void prepare();
	virtual void solve();
	virtual void finishing();

	// member variable
	Domain* domains;

private:
	std::string caseName;
	int domainCount;
};

}
#endif /* SRC_BASE_CASE_CASE_H_ */
