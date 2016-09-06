#ifndef PET_H
#define PET_H

/*Represent a pet, an animal owned by an Owner*/

#include"animal.h"

class Pet: public Animal{
  private:
    QString breed;
    QString fur;
    QString category;

  public:
    Pet(const QString&, const unsigned int);
    Pet(const QString&, const unsigned int, const AnimalData&);
    Pet(const QString&, const unsigned int, const AnimalData&, const QString&, const QString&, const QString&);
    Pet(const QJsonObject&);

    QString getBreed() const;
    QString getFur() const;
    QString getCategory() const;

    void setBreed(const QString&);
    void setFur(const QString&);
    void setCategory(const QString&);

    virtual QString typeOfAnimal() const;
    virtual void saveObj(QJsonObject&);
};

#endif // PET_H
