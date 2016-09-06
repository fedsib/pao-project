#ifndef PAOCONTAINER_H
#define PAOCONTAINER_H

/*A custom container for PAO's objects */

#include<iostream>
#include"abstractvisit.h"

class PaoContainer{

  private:
    friend class iterator;
    friend class const_iterator;
    class node;

    class smartPointer{
      public:
        node* punt;

        smartPointer(node* p=0);
        smartPointer(const smartPointer&);
        smartPointer& operator=(const smartPointer&);
        ~smartPointer();

        bool operator==(const smartPointer&) const;
        bool operator!=(const smartPointer&) const;

        node& operator*() const;
        node* operator->() const;
    };

    class node{
      public:
        AbstractVisit* info;
        smartPointer next;
        int count_ref;

        node();
        node(AbstractVisit*, const smartPointer&);
    };

    smartPointer sp_head;
    int container_size;

  public:
    PaoContainer();
    PaoContainer(const PaoContainer&);
    class iterator{
      private:
        friend class PaoContainer;
        PaoContainer::smartPointer it;

      public:
        bool operator==(iterator) const;
        bool operator!=(iterator) const;

        AbstractVisit& operator*() const;
        AbstractVisit* operator->() const;

        iterator& operator++();
        iterator operator++(int);
    };
    class const_iterator{
      private:
        friend class PaoContainer;
        PaoContainer::smartPointer it;

      public:
        bool operator==(const_iterator) const;
        bool operator!=(const_iterator) const;

        const AbstractVisit& operator*() const;
        const AbstractVisit* operator->() const;

        const_iterator& operator++();
        const_iterator operator++(int);
    };

    AbstractVisit* operator[](iterator) const;

    int size() const;
    bool isEmpty() const;
    bool contains(QString) const;
    AbstractVisit* obtainVisitForEdit(QString key);
    void remove(QString);
    void push_front(AbstractVisit*);
    void push_back(AbstractVisit*);

    PaoContainer::iterator begin();
    PaoContainer::iterator end();
    PaoContainer::const_iterator const_begin() const;
    PaoContainer::const_iterator const_end() const;
};

#endif // PAOCONTAINER_H
