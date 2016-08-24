#include "paocontainer.h"

/*node*/
PaoContainer::node::node(): count_ref(0) {}

PaoContainer::node::node(AbstractVisit* visit, const smartPointer& sp): info(visit), next(sp), count_ref(0) {}

/*smartPointer*/
PaoContainer::smartPointer::smartPointer(node* n) : punt(n){
  if(punt)
    punt->count_ref++;
}

PaoContainer::smartPointer::smartPointer(const smartPointer& sp): punt(sp.punt){
  if (punt != 0)
    punt->count_ref++;
}

PaoContainer::smartPointer& PaoContainer::smartPointer::operator=(const smartPointer& sp){
  if (this != &sp){
    node* tmp = punt;
    punt = sp.punt;
    if (punt)
      punt->count_ref++;
      if (tmp){
        tmp->count_ref--;
        if (tmp->count_ref == 0)
          delete tmp;
        }
    }
  return *this;
}

PaoContainer::smartPointer::~smartPointer(){
  if(punt){
    punt->count_ref--;
    if (punt->count_ref == 0)
      delete punt;
    }
}

bool PaoContainer::smartPointer::operator==(const smartPointer& sp) const{
  return punt == sp.punt;
}

bool PaoContainer::smartPointer::operator!=(const smartPointer& sp) const{
  return punt != sp.punt;
}

class PaoContainer::node& PaoContainer::smartPointer::operator*() const{
  return *punt;
}

class PaoContainer::node* PaoContainer::smartPointer::operator->() const{
  return punt;
}

/*iterator*/

bool PaoContainer::iterator::operator==(iterator iter) const{
  return it == iter.it;
}

bool PaoContainer::iterator::operator!=(iterator iter) const{
  return it != iter.it;
}

AbstractVisit& PaoContainer::iterator::operator*() const{
  return *(it.punt->info); //friendship
}

PaoContainer::iterator& PaoContainer::iterator::operator++(){
  if (it.punt)
    it = it->next;
    return *this;
}

PaoContainer::iterator PaoContainer::iterator::operator++(int){
  iterator aux = *this;
  if(it.punt)
    it = it->next;
    return aux;
}

/*const_iterator*/

bool PaoContainer::const_iterator::operator==(const_iterator iter) const{
  return it == iter.it;
}

bool PaoContainer::const_iterator::operator!=(const_iterator iter) const{
  return it != iter.it;
}

/*const AbstractVisit& PaoContainer::const_iterator::operator*() const{
  return *(it.punt->info);
}*/

PaoContainer::const_iterator& PaoContainer::const_iterator::operator++(){
  if(it.punt)
    it = it->next;
  return *this;
}

PaoContainer::const_iterator PaoContainer::const_iterator::operator++(int){
  const_iterator aux = *this;
  if(it.punt)
    it = it->next;
  return aux;
}

/*PaoContainer*/

PaoContainer::PaoContainer() : container_size(0){}

PaoContainer::PaoContainer(const PaoContainer& pc) : sp_head(pc.sp_head) {

 if(sp_head->next != 0)
   sp_head->count_ref++;

}

AbstractVisit* PaoContainer::operator[](iterator iter) const{
  return iter.it.punt->info;
}

int PaoContainer::size() const{
  return container_size;
}

bool PaoContainer::isEmpty() const{
  return container_size == 0;
}

void PaoContainer::remove(const QDateTime& dt, const unsigned int aID){
  smartPointer p = sp_head;
  smartPointer prec, copy;
  smartPointer origin = sp_head;
  sp_head = 0;

  while (p!=0 && !(p->info->getDate() == dt && p->info->getAnimalID() == aID)){
    copy = new PaoContainer::node(p->info, p->next);
    if(prec ==0)
      sp_head = copy;
    else
      prec->next = copy;
    prec = copy;
    p = p->next;
    }
    if(p ==0)
      sp_head = origin;
    else if(prec ==0){
      sp_head = p->next;
      container_size--;
    }
    else{
      prec->next = p->next;
      container_size--;
    }
}

void PaoContainer::push_front(AbstractVisit* visit){
  sp_head = new PaoContainer::node(visit, sp_head);
  container_size++;
}

void PaoContainer::push_back(AbstractVisit* visit){
  if (sp_head == 0){
    sp_head = new PaoContainer::node(visit, 0);
    container_size++;
    return;
  }

  smartPointer sp = sp_head;
  smartPointer prec, copy;
  sp_head = 0;

  while (sp!=0){
    copy = new PaoContainer::node(sp->info, sp->next);
    if(prec == 0)
      sp_head = copy;
      else
        prec->next = copy;

      sp = sp->next;
      prec = copy;
  }
  copy->next = new PaoContainer::node(visit, 0);
  container_size++;
}

class PaoContainer::iterator PaoContainer::begin(){
  PaoContainer::iterator aux;
  aux.it = sp_head; //friendship
  return aux;
}

class PaoContainer::iterator PaoContainer::end(){
  PaoContainer::iterator aux;
  aux.it = 0; //friendship
  return aux;
}

class PaoContainer::const_iterator PaoContainer::const_begin() const{
  PaoContainer::const_iterator aux;
  aux.it = sp_head; //friendship
  return aux;
}

class PaoContainer::const_iterator PaoContainer::const_end() const{
  PaoContainer::const_iterator aux;
  aux.it= 0; //friendship
  return aux;
}
