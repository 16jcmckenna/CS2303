/*
 * Customer.h
 *
 *  Created on: Feb 11, 2017
 *      Author: shawn
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "Event.h"

namespace std {

class Customer : public Event{
public:
	Customer();
	virtual ~Customer();
};

} /* namespace std */

#endif /* CUSTOMER_H_ */
