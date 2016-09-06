#ifndef ABSTRACTVISIT_H
#define ABSTRACTVISIT_H

/*Represent a generic Visit
 * animalID is a non negative number < of 4.294.967.295
 */

#include<QDate>
#include<QJsonObject>

class AbstractVisit{
  private:
    QString visitCode;
    QDate date;
    QString IDVet;
    unsigned int AnimalID;
    QString note;
    void setVisitCode();

  protected:
    double basic_price;

    AbstractVisit(const QJsonObject&);
    void saveAbsVisit(QJsonObject&) const;

  public:
    AbstractVisit(const QDate& , const QString&, const unsigned int, QString="", double=20);

    QString getVisitCode() const;
    QDate getDate() const;
    QString getIDVet() const;
    unsigned int getAnimalID() const;
    QString getNote() const;
    double getBasicPrice() const;

    void editAbsVisit(QString,QString,double);
    void setDate(const QDate&);
    void setIDVet(const QString&);
    void setNote(QString);
    void setAnimalID(const unsigned int);
    void setBasicPrice(double);

    virtual double calcPrice() const = 0;
    virtual QString typeOfVisit() const =0;
    virtual void saveObj(QJsonObject&) const = 0;
};

#endif // ABSTRACTVISIT_H
