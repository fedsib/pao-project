#ifndef ANIMAL_H
#define ANIMAL_H

/*Describe a generic PAO's Animal.
 * Every Animal must be associated with an Owner.
 */

#include"animaldata.h"
#include"abstractvisit.h"

class Animal{
  private:
    QString ownerID;
    unsigned int animalID;
    AnimalData animalInfo;

  public:
    Animal();
    Animal(const unsigned int, const AnimalData& data);

    QString getOwnerID() const;
    unsigned int getAnimalID() const;
    AnimalData& getAnimalData() const;

    virtual QString typeOfAnimal() const =0;

    void setOwnerID(const QString&);
    void setAnimalID(const unsigned int);
    void setAnimalData(const AnimalData&);
};

#endif // ANIMAL_H
