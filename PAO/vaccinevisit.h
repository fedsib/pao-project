#ifndef VACCINEVISIT_H
#define VACCINEVISIT_H

#include"abstractvisit.h"

class VaccineVisit : public AbstractVisit{
  public:
    VaccineVisit();
    VaccineVisit(const QJsonObject&);

    virtual double calcPrice() override;
    virtual QString typeOfVisit() const override;
    virtual void saveObj(QJsonObject&) override;
};
#endif // VACCINEVISIT_H
