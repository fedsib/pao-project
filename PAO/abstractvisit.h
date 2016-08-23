#ifndef ABSTRACTVISIT_H
#define ABSTRACTVISIT_H

/*Represent a generic Visit */

#include<QDateTime>

class AbstractVisit{
  private:
    QDateTime date;
    QString IDVet;
    unsigned int AnimalID;

  public:
    AbstractVisit();
    AbstractVisit(const QDateTime& , const QString&, unsigned int=0, unsigned short int=0);
    //AbstractVisit(const AbstractVisit&);
    //AbstractVisit& operator=(const AbstractVisit&);
    //virtual ~AbstractVisit()=0;

    QDateTime getDate() const;
    QString getIDVet() const;
    unsigned int getAnimalID() const;

    void setDate(const QDateTime&);
    void setIDVet(const QString&);
    void setAnimalID(const unsigned int);

    virtual void calcPrice(const short int) = 0;
    virtual QString typeOfUser() const =0;
};

#endif // ABSTRACTVISIT_H
