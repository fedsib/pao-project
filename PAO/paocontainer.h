#ifndef PAOCONTAINER_H
#define PAOCONTAINER_H

/*A custom container for PAO's objects */

#include<iostream>

template <class T>
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
        ~smartPointer();

        bool operator==(const smartPointer&);
        bool operator!=(const smartPointer&);

        node& operator*() const;
        node* operator->() const;
    };
    class node{
      public:
        T info;
        smartPointer next;
        int count_ref;

        node();
        node(const T&, const smartPointer&);
    };

    smartPointer sp_head;
    int size;

  public:
    PaoContainer();
    class iterator{
      private:
        friend class PaoContainer<T>;
        PaoContainer<T>::smartPointer it;

      public:
        bool operator==(iterator) const;
        bool operator!=(iterator) const;

        T& operator*() const;
       // T* operator->() const;

        iterator& operator++();
        iterator operator++(int);
    };
    class const_iterator{
      private:
        friend class PaoContainer<T>;
        PaoContainer<T>::smartPointer it;

      public:
        bool operator==(const_iterator) const;
        bool operator!=(const_iterator) const;

        const T& operator*() const;
        // T* operator->() const;

        const_iterator& operator++();
        const_iterator operator ++(int);
    };

    T operator [](const int) const;

    int size()const;
    bool isEmpty() const;
    void insert(const T&, int);
    void remove(const T&);
    void push_front(const T&);
    void push_back(const T&);

    PaoContainer<T>::iterator begin() const;
    PaoContainer<T>::iterator end() const;
    PaoContainer<T>::const_iterator begin() const;
    PaoContainer<T>::const_iterator end() const;
};

#endif // PAOCONTAINER_H
