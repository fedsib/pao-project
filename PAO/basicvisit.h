#ifndef BASICVISIT_H
#define BASICVISIT_H

/*The simplest type of Visit available in PAO*/

#include"abstractvisit.h"

class BasicVisit : AbstractVisit{

  public:
    virtual double calcPrice() override;
    virtual QString typeOfVisit() const override;
};

#endif // BASICVISIT_H
