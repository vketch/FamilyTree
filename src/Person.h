//Class Person represents a person
//and keeps family relation ships with the other persons

#include <string>
#include <vector>
#include <memory>

#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

namespace family_tree {

struct PersonException{
	std::string mErrorMsg="";
	PersonException(std::string errorMsg):mErrorMsg(errorMsg){;}
};

class Person;
using shPerson=std::shared_ptr<Person>;

class Person {
public:
    enum PersonSex {
        UNKNOWN = 1, MALE, FEMALE
    };

    Person(std::string fname, std::string sname="", shPerson father=nullptr, shPerson mather=nullptr,
    		Person::PersonSex sex=UNKNOWN);

    Person(Person& person) = delete;
    Person& operator=(Person& person) = delete;

    virtual ~Person() {};

    std::string getStrSex() const;

    const std::vector<shPerson>& getKids() const { return mKids; }

    const std::vector<shPerson>& getSpouses() const { return mSpouses; }

    unsigned long getID() const { return mID;   }

    /*  This function add  spouse partner
     *  return true if it has been added successfully
     *  or false if not (for example these persons are spouse partners already
    */
    bool addSpouse(shPerson person);

    /*  This function add person as kid.
     *  return true if person has been added successfully
     *  or false if not (for example this person is kid  already
    */
    bool addKid(shPerson kid);

    void printInfo() const;

    shPerson getFather() const {
		return mFather;
	}

	const std::string& getFname() const {
		return mFname;
	}

	unsigned long getId() const {
		return mID;
	}

	void setId(unsigned long id = 0) {
		mID = id;
	}

	shPerson getMather() const {
		return mMather;
	}

	PersonSex getSex() const {
		return mSex;
	}

	void setSex(PersonSex sex = Person::UNKNOWN) {
		mSex = sex;
	}

	const std::string& getSname() const {
		return mSname;
	}

	void setSname(const std::string& sname = "") {
		mSname = sname;
	}

private:
    unsigned long mID = 0; // Person Counter
    std::string mFname;        //first name
    std::string mSname = "";   // second name
    shPerson mFather = nullptr;   // Person's father
    shPerson mMather = nullptr;  // Person's mather
    PersonSex mSex = Person::UNKNOWN; // Person sex
    std::vector<shPerson> mKids;    // Person's kids
    std::vector<shPerson> mSpouses; // // Person's spouses

};

} /* namespace fm_tree */

#endif /* SRC_PERSON_H_ */
