/*
 * CaseSettings.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: choiminho
 */

#include "CaseSettings.h"

namespace SupersonicCombustion {

CaseSettings::CaseSettings(int argc, char** argv) {
	std::string settingsFilename;

	if (argc == 2){
		settingsFilename = argv[1];
	}
	else {
		settingsFilename = "settings.info";
	}

	// Setting file would be written in info format.
	boost::property_tree::info_parser::read_info(settingsFilename, settings);

}

CaseSettings::~CaseSettings() {
	// TODO Auto-generated destructor stub
}

} /* namespace SupersonicCombustion */
