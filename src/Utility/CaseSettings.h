/*
 * CaseSettings.h
 *
 *  Created on: Dec 17, 2014
 *      Author: choiminho
 */

#ifndef SRC_UTILITY_CASESETTINGS_H_
#define SRC_UTILITY_CASESETTINGS_H_

#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/info_parser.hpp"

namespace comPcomB {

class CaseSettings {
public:
	CaseSettings(int, char**);
	virtual ~CaseSettings();
	boost::property_tree::ptree info;


};

} /* namespace SupersonicCombustion */
#endif /* SRC_UTILITY_CASESETTINGS_H_ */
