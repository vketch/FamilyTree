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
      Person* mather = NULL, Person::Sex sex = Person::UNKNOWN);

  virtual ~Person();

  std::string getFname() const;
  std::string getSname() const;
  std::string getStrSex() const;
  Person::Sex getSex() const;
  unsigned long getID() const;
  const std::vector<Person*>& getKids() const;
  void printInfo() const;

  void addSpouse(Person* person);
  const std::vector<Person*>& getSpouses() const;

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

} // namespace family_tree

#endif /* SRC_PERSON_H_ */
