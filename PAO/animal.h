#ifndef ANIMAL_H
#define ANIMAL_H

/*Describe a generic PAO's Animal.
 * Every Animal must be associated with an Owner.
 * Every Animal has a clinicalSheet (a PaoContainer of AbstractVisits*) associated */

#include"animaldata.h"
#include"abstractvisit.h"
#include"paocontainer.h"

class Animal{
  private:
    unsigned int animalID;
    AnimalData animalInfo;
    PaoContainer clinicalSheet;

  public:
    Animal();
    Animal(const unsigned int, const AnimalData&data, const PaoContainer&);

    virtual QString typeOfAnimal() const =0;
};

#endif // ANIMAL_H
