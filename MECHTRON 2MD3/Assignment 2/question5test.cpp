#include <cstdlib>
#include <iostream>

typedef std::string Elem;
using namespace std;

class DNode {  // doubly linked list node
 private:
  Elem name;                 // node element value
  int score;
  DNode* prev;               // previous node in list
  DNode* next;               // next node in list
  friend class DLinkedList;  // allow DLinkedList access
};

class DLinkedList {  // doubly linked list
 public:
  DLinkedList();                 // constructor
  ~DLinkedList();                // destructor
  bool empty() const;            // is list empty?
  const Elem& front() const;     // get front element
  const Elem& back() const;      // get back element
  void addFront(const Elem& name);  // add to front of list
  void addBack(const Elem& name);   // add to back of list
  void removeFront();            // remove from front
  void removeBack();             // remove from back
  DNode* getHeader();
  bool UpdateScore(std::string name, int score);
  void Print();
  //----------------------------------------------
  int Size();
  void AddScoreInOrder(std::string name, int score);
  void RemoveScore(int index);
 private:                        // local type definitions
  DNode* header;                 // list sentinels
  DNode* trailer;

 protected:                           // local utilities
  void add(DNode* x, const Elem& name, int score);  // insert new node before v
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
    removeFront();  //  remove all but sentinels
  }
  delete header;  //  remove the sentinels
  delete trailer;
}

bool DLinkedList::empty() const {  // is list empty?
  return (header->next == trailer);
}

void DLinkedList::add(DNode* x, const Elem& name, int score) {
  DNode* newNode = new DNode;
  newNode->name = name;
  newNode->score = score;
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

void DLinkedList::removeFront() {  // remove from font
  remove(header->next);
}

void DLinkedList::removeBack() {  // remove from back
  remove(trailer->prev);
}


DNode* DLinkedList::getHeader(){
    return header;
}

int DLinkedList::Size(){                        // double check if this is right
    static DNode* cur = header->next; 
    if (cur == NULL){
        cur = header->next; 
    }
    if (cur -> next == trailer){
        cur = NULL; 
        return 1; 
    }
    cur = cur->next; 
    return 1 + Size(); 
}


void DLinkedList::AddScoreInOrder(std::string name, int score){         // test later
    DNode* newNode = new DNode;
    DNode* current = header->next;
    newNode->name = name;
    newNode->score = score;
    if(header->next == trailer){
        add(header, name, score);
    } else {
        while (current->score > newNode->score  && current!=trailer){
            current = current ->next;
        }
        add(current, name, score);
    }
}

void DLinkedList:: RemoveScore(int index){
    DNode* current = header->next;
    if(current == trailer){
        return;
    }
    if(index<0 || index > Size()){
        return;
    }
    for(int i =0; i<index;i++){
        current = current->next;
    }
    remove(current);
}


bool DLinkedList:: UpdateScore(std::string name, int score){
    DNode* current = header->next;
    while (current->name != name && current!=trailer){
        current  = current->next;
    }
    if(current == trailer){
        return 0;
    }
    current->score = score;
    return 1;
}

void DLinkedList:: Print(){
    static DNode* current = header->next;
    if (current == NULL){
        current = header->next; 
    }
    if(current->next==trailer){
        cout << '{' << current->name << ',' << current->score << '}' << endl; 
        current = NULL; 
        return; 
    }
    std::cout << '{' << current->name << ',' << current->score << "}->";
    current = current->next;
    Print();
}



int main() {
    DLinkedList scores;
    scores.AddScoreInOrder("Jeff", 7);
    scores.AddScoreInOrder("Jen", 9);
    scores.AddScoreInOrder("Ilya", 3);
    scores.AddScoreInOrder("Sara", 10);
    scores.AddScoreInOrder("Sam", 11);
    // Test size function
    cout << "Number of scores is " << scores.Size() << endl;
    //scores.Print();
    // Test remove function
    // scores.RemoveScore(3);
    // cout << "Number of scores is now " << scores.Size() << endl;
    // scores.Print();
    // // Test update function
    // if (scores.UpdateScore("Jeff",6))
    // scores.Print();
    // Test copy construcor
    // DLinkedList scores_copy_1(scores);
    // scores.UpdateScore("Jen",5);
    // scores.Print();
    // scores_copy_1.Print();
    // Test assignment operator overload
    // DLinkedList scores_copy_2 = scores_copy_1;
    // scores_copy_1.UpdateScore("Jen",5);
    // scores_copy_1.Print();
    // scores_copy_2.Print();
    // Test OrderByName function
    //scores_copy_2.OrderByName();
    //scores_copy_2.Print();
}
