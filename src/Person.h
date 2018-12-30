/*
 * Person.h
 *
 *  Created on: 30 груд. 2018 р.
 *      Author: root
 */

#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include <string>

struct PersonException{
    std::string mErrorMsg="";
    PersonException(std::string errorMsg):mErrorMsg(errorMsg){;}
};

namespace family_tree {

class Person {
public:
    enum PersonType {
        GOD = 1, ANGEL, HUMAN
    };
    Person(std::string fname, PersonType type);

    virtual ~Person() {};

    const std::string& getFname() const {
        return mFname;
    }

    const PersonType& getType() const {
        return mType;
    }

    unsigned long getID() const {
        return mID;
    }

    void setId(unsigned long id = 0) {
        mID = id;
    }

private:
    unsigned long mID = 0; // Person ID
    PersonType mType;      // Person type
    std::string mFname;     //first name
};

} /* namespace family_tree */

#endif /* SRC_PERSON_H_ */
