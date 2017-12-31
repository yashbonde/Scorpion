/*
scorpion_core header file for Scorpion Framework, written for Texas Instruments
Launchpad devices and Arduino. This framework aims to implement machine
learning on small embedded devices.

This header file contain the definition of Matrix class which will be used
in the scorpion framework.

See license for legal queries.
2017, Yash Bonde
*/

#ifndef SCORPION_CORE_H
#define SCORPION_CORE_H

// this is the only header we need as this is the core and only defines
// the matrix class, all the other files we use will include this header
#include "scopion_core.h"

// Matrix in Scorpion is a class
class Matrix
{
public:
	matrix(int x, int y);
	int shape();
private:
	int x_, y_;
	
};

#endif