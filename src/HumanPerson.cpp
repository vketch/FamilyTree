/* Implementation of Person class
 */
#include <iostream>

#include "HumanPerson.h"
#include "Person.h"

namespace family_tree {

HumanPerson::HumanPerson(std::string fname, std::string sname,
        HumanPerson* father, HumanPerson* mather, HumanPerson::PersonSex sex) :
        Person( fname, Person::HUMAN ),
        mSname(sname), mFather(father), mMather(mather), mSex(sex) {

    if (mFather != NULL)
        mFather->mKids.push_back(this);

    if (mMather != NULL)
        mMather->mKids.push_back(this);
}

std::string HumanPerson::getStrSex() const {
    switch (mSex) {
    case HumanPerson::UNKNOWN:
        return "UNKNOWN";

    case HumanPerson::MALE:
        return "MALE";

    case HumanPerson::FEMALE:
        return "FEMALE";

    default:
        return "UNDEFINED";

    }
}

void HumanPerson::printInfo() const {
    std::cout << getFname() + " " + mSname + "(" + getStrSex() + ")" << "[" <<
            getID() << "]" << std::endl;

    if (mFather != NULL)
        std::cout << "	Father: " << mFather->getFname() << std::endl;

    if (mMather != NULL)
        std::cout << "	Mather: " << mMather->getFname() << std::endl;

    if (!mSpouses.empty()) {
        std::cout << "	Spouses: ";
        for (HumanPerson* spouse : mSpouses)
            std::cout << spouse->getFname() << ',';
        std::cout << std::endl;
    }

    if (!mKids.empty()) {
        std::cout << "	Kids: ";
        for (HumanPerson* kid : mKids)
            std::cout << kid->getFname() << ',';
        std::cout << std::endl;
    }
}

bool HumanPerson::addSpouse(HumanPerson* person) {
    for (HumanPerson* spouse : mSpouses)
        if (spouse == person)
            return false;
    mSpouses.push_back(person);
    person->mSpouses.push_back(this);
    return true;
}

bool HumanPerson::addKid(HumanPerson& person) {
    for (HumanPerson* kid : mKids) {
        //ToDo kid should has different name else this person is  added as Kid
        if (kid == &person)
            return false;
    }
    mKids.push_back(&person);

    // make this one of parent(father or mather) for the person
    if (mSex == PersonSex::MALE)
        person.mFather = this;
    else if (mSex == PersonSex::FEMALE)
        person.mMather = this;

    return true;
}

} /* namespace fm_tree */
