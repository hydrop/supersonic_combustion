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
#include "src/base/Domain/Domain.h"
#include "src/base/Domain/SimpleDomain.h"

namespace SupersonicCombustion{

class Case{
public:
	// constructor & destructor
	Case(CaseSettings&);
	virtual ~Case();

	// getter & setter
	void setCaseName(std::string);

	virtual void prepare();
	virtual void solve();
	virtual void finishing();

private:
	std::string caseName;
	Domain* domain;
};

}
#endif /* SRC_BASE_CASE_CASE_H_ */
