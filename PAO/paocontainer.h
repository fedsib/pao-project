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
        smartPointer& operator=(const smartPointer&);
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
    int container_size;

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

    int size() const;
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

/*Definition of smartPointer*/
template <class T>
PaoContainer<T>::smartPointer::smartPointer(PaoContainer::node* sp): punt(sp){
  if(punt)
    punt->count_ref++;
}

template <class T>
PaoContainer<T>::smartPointer::smartPointer(const PaoContainer<T>::smartPointer& sp): punt(sp.punt){
  if (punt)
    punt->count_ref++;
}

template <class T>
class PaoContainer<T>::smartPointer& PaoContainer<T>::smartPointer::operator=(const smartPointer& sp){
  if (this != &sp){
    node* tmp = punt;
    punt = sp.punt;
    if (punt)
      punt->count_ref++;
      if (temp){
        temp->count_ref--;
        if (temp->count_ref == 0)
          delete temp;
      }
  }
  return *this;
}

template <class T>
PaoContainer<T>::smartPointer::~smartPointer(){
  if (punt){
    punt->count_ref--;
    if (punt->count_ref == 0)
      delete punt;
  }
}

template <class T>
bool PaoContainer<T>::smartPointer::operator==(const smartPointer& sp) const{
  return punt == sp.punt;
}

template <class T>
bool PaoContainer<T>::smartPointer::operator!=(const smartPointer& sp) const{
  return punt != sp.punt;
}

template <class T>
class PaoContainer<T>::node& PaoContainer<T>::smartPointer::operator*() const{
  return *punt;
}

template <class T>
class PaoContainer<T>::node* PaoContainer<T>::smartPointer::operator->() const{
    return punt;
}

#endif // PAOCONTAINER_H
