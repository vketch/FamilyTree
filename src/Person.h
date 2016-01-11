/* Class Person represents a person in the family tree
* and keeps family relation ships with the other persons
*/

#include <string>
#include <vector>


class Person;

class Person{
public:
	enum Sex{
		UNKNOWN = 1,
		MALE,
		FEMALE
	}; 
private:
	unsigned long mId;
	std::string mFname;     //first name 
	std::string mSname;     // second name
	Person *mFather;
	Person *mMather;
	Sex mSex;
	std::vector<Person*> mKids;
	std::vector<Person*> mSpouses;

	Person( Person& person) {}    // forbid copy constructor
	Person& operator=( Person& person){} // forbid assign operator
public:
	Person( std::string fname,
            std::string sname="",
            Person* father=NULL,
            Person* mather=NULL,
			Person::Sex sex = Person::UNKNOWN			
          );

	virtual ~Person();

	std::string getFname() const;
	std::string getSname() const;	
	const std::vector<Person*>& getKids() const;
	const std::vector<Person*>& getSpouses() const;
	void printInfo() const; 
	std::string getStrSex() const;
	Person::Sex getSex() const;	
	void addSpouse( Person* person );
}; 

