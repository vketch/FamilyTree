/*
 * Kid.h
 *
 *  Created on: Oct 11, 2017
 *      Author: sadivsky
 */

#ifndef KID_H_
#define KID_H_

#include "HumanPerson.h"

namespace family_tree {

class Kid: public HumanPerson {
public:
    Kid();
    virtual ~Kid();
};

} /* namespace family_tree */

#endif /* KID_H_ */
