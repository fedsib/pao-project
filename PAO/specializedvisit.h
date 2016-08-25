#ifndef SPECIALIZEDVISIT_H
#define SPECIALIZEDVISIT_H

/*The most expensive visit. Price is the twice of the basic plus a 30%*/
#include"abstractvisit.h"

class SpecializedVisit : public AbstractVisit{
  public:
    SpecializedVisit();
    SpecializedVisit(const QJsonObject&);

    virtual double calcPrice() const override;
    virtual QString typeOfVisit() const override;
    virtual void saveObj(QJsonObject&) const override;
};

#endif // SPECIALIZEDVISIT_H
