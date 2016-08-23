#ifndef SPECIALIZEDVISIT_H
#define SPECIALIZEDVISIT_H

/*The most expensive visit. Price is the twice of the basic plus a 30%*/
#include"abstractvisit.h"

class SpecializedVisit : public AbstractVisit{
  public:
    virtual double calcPrice() override;
    virtual QString typeOfVisit() const override;
};

#endif // SPECIALIZEDVISIT_H
