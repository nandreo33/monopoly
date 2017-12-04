/*
 * nonproperty.h
 *
 *  Created on: Dec 3, 2017
 *
 * NonProperty header declares injail and NonProperty constructor
 *
 */

#ifndef NONPROPERTY_H_
#define NONPROPERTY_H_

#include <string>
#include <iostream>
#include "space.h"



class NonProperty : public Space
{
public:
	int in_jail;
NonProperty(string, int, bool);
};

#endif /* NONPROPERTY_H_ */
