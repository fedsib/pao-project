#ifndef BASICVISIT_H
#define BASICVISIT_H

/*The simplest type of Visit available in PAO*/

#include"abstractvisit.h"

class BasicVisit : AbstractVisit{

  public:

    BasicVisit();
    BasicVisit(const QJsonObject&);
    virtual double calcPrice() override;
    virtual QString typeOfVisit() const override;

    virtual void saveObj(QJsonObject&) override;
};

#endif // BASICVISIT_H
