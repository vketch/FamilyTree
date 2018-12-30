//Class HumanPerson represents a Human person
//and keeps family relation ships with the other persons

#ifndef SRC_HUMAN_PERSON_H_
#define SRC_HUMAN_PERSON_H_

#include <vector>
#include "Person.h"

namespace family_tree {

class HumanPerson;

class HumanPerson: public Person {
public:
    enum PersonSex {
        UNKNOWN = 1, MALE, FEMALE
    };

    HumanPerson(std::string fname, std::string sname="", HumanPerson* father=NULL, HumanPerson* mather=NULL,
    		HumanPerson::PersonSex sex=UNKNOWN);

    HumanPerson(HumanPerson& person) = delete;
    HumanPerson& operator=(HumanPerson& person) = delete;

    virtual ~HumanPerson() {};

    std::string getStrSex() const;

    const std::vector<HumanPerson*>& getKids() const { return mKids; }

    const std::vector<HumanPerson*>& getSpouses() const { return mSpouses; }

    /*  This function add  spouse partner
     *  return true if it has been added successfully
     *  or false if not (for example these persons are spouse partners already
    */
    bool addSpouse(HumanPerson* person);

    /*  This function add person as kid.
     *  return true if person has been added successfully
     *  or false if not (for example this person is kid  already
    */
    bool addKid(HumanPerson& kid);

    void printInfo() const;

	HumanPerson* getFather() const {
		return mFather;
	}

	HumanPerson* getMather() const {
		return mMather;
	}

	PersonSex getSex() const {
		return mSex;
	}

	void setSex(PersonSex sex = HumanPerson::UNKNOWN) {
		mSex = sex;
	}

	const std::string& getSname() const {
		return mSname;
	}

	void setSname(const std::string& sname = "") {
		mSname = sname;
	}

private:
    std::string mSname = "";   // second name
    HumanPerson *mFather = NULL;   // Person's father
    HumanPerson *mMather = NULL;  // Person's mather
    PersonSex mSex = HumanPerson::UNKNOWN; // Person sex
    std::vector<HumanPerson*> mKids;    // Person's kids
    std::vector<HumanPerson*> mSpouses; // // Person's spouses
};

} /* namespace fm_tree */

#endif /* SRC_HUMAN_PERSON_H_ */
