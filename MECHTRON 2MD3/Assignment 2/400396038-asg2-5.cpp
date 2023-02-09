#include <cstdlib>
#include <iostream>
#include <string>
typedef int Elem;
typedef std::string Name;
using namespace std;

class DNode {  // doubly linked list node
 private:
  Elem score;                 // node element value
  Name name;
  DNode* prev;               // previous node in list           
  DNode* next;               // next node in list
  friend class DLinkedList;  // allow DLinkedList access
};                  

class DLinkedList {  // doubly linked list
 public:
  DLinkedList();                 // constructor
  ~DLinkedList();                // destructor
  bool empty() const;            // is list empty?
  int Size(DNode* header, int count = 0);
  void AddScoreInOrder(const Elem& e, const Name& name);   // add to back of list
 private:                        // local type definitions
  DNode* header;                 // list sentinels
  DNode* trailer;
 protected:                           // local utilities
  void add(DNode* v, const Elem& e, const Name& name);  // insert new node before v
  void remove(DNode* v);              // remove node v
};

DLinkedList::DLinkedList() {  // constructor
  header = new DNode;         // create sentinels
  trailer = new DNode;
  header->next = trailer;  // have them point to each other
  trailer->prev = header;
  header->prev = NULL;
  trailer->next = NULL;
}

DLinkedList::~DLinkedList() {  // destructor
  while (!empty()) {
    remove(header->next);  //  remove all but sentinels
  }
  delete header;  //  remove the sentinels
  delete trailer;
}

bool DLinkedList::empty() const {  // is list empty?
  return (header->next == trailer);
}

void DLinkedList::add(DNode* x, const Elem& value, const Name& name) {
  DNode* newNode = new DNode;
  newNode->score = value;
  newNode->name = name;
  newNode->next = x->next;
  newNode->prev = x;
  x->next->prev = newNode;
  x->next = newNode;
}



void DLinkedList::remove(DNode* v) {  // remove node v
  DNode* u = v->prev;                 // predecessor
  DNode* w = v->next;                 // successor
  u->next = w;                        // unlink v from list
  w->prev = u;
  delete v;
}


//---------------------------------------------

int DLinkedList::Size(DNode* cur, int count = 0){
    if (cur == NULL) {
        return;
    }
    if (cur->score != NULL){
        count++;
    }
    Size(cur->next);
}

void DLinkedList::AddScoreInOrder(const Elem& e,  const Name& name) {  // add to back of list
  add(trailer->prev, e, name);
}









int main() {
    DLinkedList dll;
    dll.AddScoreInOrder(1, "one");
    dll.AddScoreInOrder(2, "two");
    dll.AddScoreInOrder(3, "three");
    int counter = dll.Size();
    cout << counter << endl;
  //std::cout << dll.front() << std::endl;
}
