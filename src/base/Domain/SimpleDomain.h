/*
 * SimpleDomain.h
 *
 *  Created on: Dec 16, 2014
 *      Author: choiminho
 */

#ifndef LIB_DOMAIN_SIMPLEDOMAIN_H_
#define LIB_DOMAIN_SIMPLEDOMAIN_H_

#include "Domain.h"
#include "include/define.h"

namespace SupersonicCombustion {

class SimpleDomain: public Domain {
public:
	SimpleDomain();
	virtual ~SimpleDomain();

	int x, y;
	real* temperature;
};

}
#endif /* LIB_DOMAIN_SIMPLEDOMAIN_H_ */
