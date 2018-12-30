#include <HumanPerson.h>
#include <iostream>

using namespace std;
using namespace family_tree;

int main() {
  vector<HumanPerson *> BblPrs;   // Bible Persons

  HumanPerson *Adam = new HumanPerson("Adam", "", NULL, NULL, HumanPerson::MALE);
  BblPrs.push_back(Adam);
  Adam->printInfo();

  HumanPerson *Eva = new HumanPerson("Eva", "", NULL, NULL, HumanPerson::FEMALE);
  Adam->addSpouse(Eva);
  Eva->printInfo();

  HumanPerson Kain("Kain", "", Adam, Eva, HumanPerson::MALE);
  HumanPerson Avel("Avel", "", Adam, Eva, HumanPerson::MALE);
  HumanPerson Sum("Sum", "", Adam, Eva, HumanPerson::MALE);

  Adam->printInfo();

  HumanPerson Enoh("Enoh", "", &Kain, NULL, HumanPerson::MALE);

  HumanPerson Irad("Irad", "", &Enoh, NULL, HumanPerson::MALE);
  HumanPerson Igujal("Igujal", "", &Irad, NULL, HumanPerson::MALE);

  Kain.printInfo();
  Enoh.printInfo();

}
