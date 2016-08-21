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

        bool operator==(const smartPointer&);
        bool operator!=(const smartPointer&);

        node& operator*() const;
        node* operator->() const;
    };

    class node{
      public:
        AbstractVisit* info;
        smartPointer next;
        int count_ref;

        node();
        node(const AbstractVisit&, const smartPointer&);
    };

    smartPointer sp_head;
    int container_size;

  public:
    PaoContainer();
    //PaoContainer(const PaoContainer&);
    class iterator{
      private:
        friend class PaoContainer;
        PaoContainer::smartPointer it;

      public:
        bool operator==(iterator) const;
        bool operator!=(iterator) const;

        AbstractVisit& operator*() const;
       // AbstractVisit* operator->() const;

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
        // AbstractVisit* operator->() const;

        const_iterator& operator++();
        const_iterator operator ++(int);
    };

    AbstractVisit& operator [](const int) const;

    int size() const;
    bool isEmpty() const;
    void insert(const AbstractVisit&, int);
    void remove(const AbstractVisit&);
    void push_front(const AbstractVisit&);
    void push_back(const AbstractVisit&);

    PaoContainer::iterator begin() const;
    PaoContainer::iterator end() const;
    PaoContainer::const_iterator const_begin() const;
    PaoContainer::const_iterator const_end() const;
};

#endif // PAOCONTAINER_H
