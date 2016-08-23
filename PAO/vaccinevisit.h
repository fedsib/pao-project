#ifndef VACCINEVISIT_H
#define VACCINEVISIT_H

#include"abstractvisit.h"

class VaccineVisit : public AbstractVisit{
  public:
    virtual double calcPrice() override;
    virtual QString typeOfVisit() const override;
};
#endif // VACCINEVISIT_H