/*
 * Grid.h
 *
 *  Created on: Mar 9, 2015
 *      Author: choiminho
 */

#ifndef SRC_CONTAINER_GRID_GRID_H_
#define SRC_CONTAINER_GRID_GRID_H_

#include "include/define.h"
#include "include/dimension.h"

namespace comPcomB {

class Grid {
public:
	Grid();
	virtual ~Grid();
/*
	r			density (kg/m^3)
    ru, rv, rw  density * velocity (kg/(m^2*s))
    re          density * internal total energy (kg/m^3*J/kg = J/m^3)

    u, v, w     velocity (m/s)
    h           enthalpy (J/m^3)
    T           temperature (K)
    gamma       specific heat ratio
    a           speed of sound (m/s)

    Y           mass fraction (ND)
    c           concentration (mole/m3)
    rY          density * mass fraction
*/
	real* xcoord;
	real* ycoord;
	real* zcoord;

	real* gxx;
	real* gxy;
	real* gxz;
	real* gyx;
	real* gyy;
	real* gyz;
	real* gzx;
	real* gzy;
	real* gzz;
	real* gj;
	real* contraNorm_x;
	real* contraNorm_y;
	real* contraNorm_z;

	real* r;
	real* ru;
	real* rv;
	real* rw;
	real* re;
	real** rY;

	real* u;
	real* v;
	real* w;
	real* h;
	real* T;
	real* gamma;
	real* a;
	real* Y;
	real* c;

private:
	dim size;
	int domainIdx;
	int gridIdx;
};

} /* namespace SupersonicCombustion */
#endif /* SRC_CONTAINER_GRID_GRID_H_ */
