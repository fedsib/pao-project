#ifndef PET_H
#define PET_H

/*Represent a pet, an animal owned by an Owner*/

#include<QString>
#include"animal.h"

class Pet: public Animal{
  private:
    QString breed;
    QString fur;
    QString category;

  public:
    Pet();
    Pet(const QString&, const QString&, const QString&);

    QString getBreed() const;
    QString getFur() const;
    QString getCategory() const;

    void setBreed(const QString&);
    void setFur(const QString&);
    void setCategory(const QString&);

    virtual QString typeOfAnimal() const override;
};

#endif // PET_H
