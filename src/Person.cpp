/* Implementation of Person class
 */
#include <iostream>
#include "Person.h"

namespace family_tree {

Person::Person(std::string fname, std::string sname, Person* father,
        Person* mather, Person::PersonSex sex):
	mFname(fname), mSname(sname), mFather(father), mMather(mather), mSex(sex){

    if( fname.size()==0 )
    	throw PersonException("Person should has first name at least");

    if (mFather != NULL)
        mFather->mKids.push_back(this);

    if (mMather != NULL)
        mMather->mKids.push_back(this);
}

std::string Person::getStrSex() const {
    switch (mSex) {
    case Person::UNKNOWN:
        return "UNKNOWN";

    case Person::MALE:
        return "MALE";

    case Person::FEMALE:
        return "FEMALE";

    default:
        return "UNDEFINED";

    }
}

void Person::printInfo() const {
    std::cout << mFname + " " + mSname + "(" + getStrSex() + ")" << "[" << mID
            << "]" << std::endl;

    if (mFather != NULL)
        std::cout << "	Father: " << mFather->getFname() << std::endl;

    if (mMather != NULL)
        std::cout << "	Mather: " << mMather->getFname() << std::endl;

    if (!mSpouses.empty()) {
        std::cout << "	Spouses: ";
        for(Person* spouse : mSpouses)
            std::cout << spouse->mFname << ',';
        std::cout << std::endl;
    }

    if (!mKids.empty()) {
        std::cout << "	Kids: ";
          for(Person* kid : mKids)
              std::cout << kid->mFname << ',';
        std::cout << std::endl;
    }
}

bool Person::addSpouse(Person* person) {
	for(Person* spouse: mSpouses)
		if( spouse == person )
			return false;
	mSpouses.push_back(person);
    person->mSpouses.push_back(this);
	return true;
}

bool Person::addKid(Person& person) {
	for(Person* kid: mKids){
	    //ToDo kid should has different name else this person is  added as Kid
		if( kid == &person )
			return false;
	}
	mKids.push_back(&person);

	// make this one of parent(father or mather) for the person
	if( mSex == PersonSex::MALE )
		person.mFather = this;
	else if( mSex == PersonSex::FEMALE )
		person.mMather = this;

	return true;
}

} /* namespace fm_tree */

