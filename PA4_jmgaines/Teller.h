/*
 * Teller.h
 *
 *  Created on: Feb 11, 2017
 *      Author: shawn
 */

#ifndef TELLER_H_
#define TELLER_H_

#include "Event.h"

namespace std {

class Teller : public Event {
public:
	Teller();
	virtual ~Teller();
};

} /* namespace std */

#endif /* TELLER_H_ */
