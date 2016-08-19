#ifndef PAOCONTAINER_H
#define PAOCONTAINER_H

/*A custom container for PAO's objects */

#include<iostream>

template <typename T>
class PaoContainer{

  private:
    friend class iterator;
    friend class const_iterator;

    class node;

    class smartPointer{

      private:

      public:
        smartPointer(item* p=0);
        smartPointer(const PaoContainer<T>::smartPointer&);
        ~smartPointer();
        node* punt;
    }

  public:
    PaoContainer();
};

#endif // PAOCONTAINER_H
