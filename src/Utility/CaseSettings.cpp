/*
 * CaseSettings.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: choiminho
 */

#include <iostream>
#include "CaseSettings.h"

namespace comPcomB {

CaseSettings::CaseSettings(int argc, char** argv) {
	std::string settingsFilename;

	if (argc > 1){
		settingsFilename = argv[1];
		// TODO for robust load, argv should be checked
		// whether it is a proper file path.
	}
	else {
		settingsFilename = "settings.info";
	}

	// Setting file would be written in info format.
	boost::property_tree::info_parser::read_info(settingsFilename, info);


	// without 2nd param, type should be stated
	// 	e.g. cout << info.get<std::string>("key2");
	std::cout << info.get("key2.subkey.", "failed");

}

CaseSettings::~CaseSettings() {
}

} /* namespace SupersonicCombustion */
