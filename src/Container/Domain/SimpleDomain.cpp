/*
 * SimpleDomain.cpp
 *
 *  Created on: Dec 16, 2014
 *      Author: choiminho
 */

#include "SimpleDomain.h"

namespace comPcomB {

SimpleDomain::SimpleDomain() {
	x=100;
	y=100;
	temperature=new real[x*y];

}

SimpleDomain::~SimpleDomain() {
	delete temperature;
}

}
