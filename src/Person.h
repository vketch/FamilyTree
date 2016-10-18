//Class Person represents a person
//and keeps family relation ships with the other persons

#include <string>
#include <vector>

#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

namespace family_tree {

class Person;

class Person {
public:
    enum Sex {
        UNKNOWN = 1, MALE, FEMALE
    };

    Person(std::string fname, std::string sname = "", Person* father = NULL,
            Person* mather = NULL, Person::Sex sex = Person::UNKNOWN) {
        mFname = fname;
        mSname = sname;
        mSex = sex;
        mFather = father;
        mMather = mather;
        if (mFather != NULL)
            mFather->mKids.push_back(this);

        if (mMather != NULL)
            mMather->mKids.push_back(this);

        mID = Person::mPrsCnt;
        Person::mPrsCnt++;
    }

    virtual ~Person() {
    }
    ;

    const std::string& getFname() const {
        return mFname;
    }

    const std::string& getSname() const {
        return mSname;
    }

    const Person* getFather() const {
        return mFather;
    }
    const Person* getMather() const {
        return mMather;
    }

    Sex getSex() const {
        return mSex;
    }
    std::string getStrSex() const;

    const std::vector<Person*>& getKids() const {
        return mKids;
    }

    const std::vector<Person*>& getSpouses() const {
        return mSpouses;
    }

    void addSpouse(Person* person) {
        mSpouses.push_back(person);
        person->mSpouses.push_back(this);
    }

    unsigned long getID() const {
        return mID;
    }

    void printInfo() const;

private:
    static unsigned long mPrsCnt; // Person Counter
    unsigned long mID;
    std::string mFname;     //first name
    std::string mSname;     // second name
    Person *mFather;
    Person *mMather;
    Sex mSex;
    std::vector<Person*> mKids;
    std::vector<Person*> mSpouses;

    // forbid copy constructor
    Person(Person& person);
    // forbid assign operator
    Person& operator=(Person& person);

};

} /* namespace fm_tree */

#endif /* SRC_PERSON_H_ */
