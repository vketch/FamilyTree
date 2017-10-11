/*
 * Position.h
 *
 *  Created on: Oct 11, 2017
 *      Author: sadivsky
 */

#ifndef POSITION_H_
#define POSITION_H_

namespace family_tree {

class Position {
public:
    Position(std::string title, std::string description="")
            :mTitle(title), mDescription(description){};
    virtual ~Position(){};
protected:
    std::string mTitle;   //Position Title
    std::string mDescription;   //Position Description
};

} /* namespace family_tree */

#endif /* POSITION_H_ */
