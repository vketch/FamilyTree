#include <iostream>
#include "Person.h"

using namespace std;
using namespace family_tree;

int main() {
  vector<Person *> BblPrs;   // Bible Persons

  Person *Adam = new Person("Adam", "", NULL, NULL, Person::MALE);
  BblPrs.push_back(Adam);
  Adam->printInfo();

  Person *Eva = new Person("Eva", "", NULL, NULL, Person::FEMALE);
  Adam->addSpouse(Eva);
  Eva->printInfo();

  Person Kain("Kain", "", Adam, Eva, Person::MALE);
  Person Avel("Avel", "", Adam, Eva, Person::MALE);
  Person Sum("Sum", "", Adam, Eva, Person::MALE);

  Adam->printInfo();

  Person Enoh("Enoh", "", &Kain, NULL, Person::MALE);

  Person Irad("Irad", "", &Enoh, NULL, Person::MALE);
  Person Igujal("Igujal", "", &Irad, NULL, Person::MALE);

  Kain.printInfo();
  Enoh.printInfo();

}
