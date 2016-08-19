#ifndef ANIMAL_H
#define ANIMAL_H

/*Describe a generic PAO's Animal.
 * Every Animal must be associated with an Owner.
 * Every Animal has a clinicalSheet (a container of Visits) associated */

#include"animaldata.h"
#include"abstractvisit.h"
#include"paocontainer.h"

class Animal{
  private:
    unsigned int animalID;
    AnimalData animalInfo;
    PaoContainer<AbstractVisit*> clinicalSheet;

  public:
    Animal();
    Animal(const unsigned int, const Animal&, const std::vector<Animal*>&);
    Animal& operator=(const Animal&);
    virtual ~Animal()=0;

};

#endif // ANIMAL_H
