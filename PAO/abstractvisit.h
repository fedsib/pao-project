#ifndef ABSTRACTVISIT_H
#define ABSTRACTVISIT_H

/*Represent a generic Visit */

#include<QDateTime>

class AbstractVisit{
  private:
    QDateTime orario;
    unsigned int AnimalID;
    QString IDVet;
    unsigned short int price;

  public:
    AbstractVisit();
    AbstractVisit(const QDateTime&, const unsigned int, const QString&, const unsigned short int=0);
    AbstractVisit(const AbstractVisit&);
    AbstractVisit& operator=(const AbstractVisit&);
    virtual ~AbstractVisit()=0;

    QDateTime getOrario() const;
    unsigned int getAnimalID() const;
    QString getIDVet() const;
    unsigned short int getPrice() const;

    void setOrario(const QDateTime&);
    void setAnimalID(const unsigned int);
    void setIDVet(const QString&);
    virtual void setPrice(const short int) = 0;

};

#endif // ABSTRACTVISIT_H
