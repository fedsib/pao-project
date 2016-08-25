#ifndef BASICVISIT_H
#define BASICVISIT_H

/*The simplest type of Visit available in PAO*/

#include"abstractvisit.h"

class BasicVisit : public AbstractVisit{

  public:

    BasicVisit();
    BasicVisit(const QJsonObject&);
    virtual double calcPrice() const override;
    virtual QString typeOfVisit() const override;

    virtual void saveObj(QJsonObject&) const override;
};

#endif // BASICVISIT_H
