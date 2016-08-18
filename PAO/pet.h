#ifndef PET_H
#define PET_H

#include<QString>

class Pet: public Animal{
  private:
    QString breed;
    QString fur;
    QString category;

  public:
    Pet();

    Pet(const QString&, const QString&, const QString&, category);
    Pet(const Pet&);
    Pet& operator=(const Pet&);
    ~Pet();

    QString getBreed() const;
    QString getFur() const;
    QString getCategory() const;

    void setBreed(const QString&);
    void setFur(const QString&);
    void setCategory(const QString&);
};

#endif // PET_H
