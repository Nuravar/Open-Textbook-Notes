#include <cstdlib>
#include <iostream>
using namespace std;

template <typename E>  // forward declaration of SLinkedList
class SLinkedList;

template <typename E>
class SNode {  // singly linked list node
 private:
  E elem;                       // linked list element value
  SNode<E>* next;               // next item in the list
  friend class SLinkedList<E>;  // provide SLinkedList access
};

template <typename E>
class SLinkedList {  // a singly linked list
 public:
  SLinkedList();              // empty list constructor
  ~SLinkedList();             // destructor
  bool empty() const;         // is list empty?
  const E& front() const;     // return front element
  void addFront(const E& e);  // add to front of list
  void removeFront();         //  remove front of list
  //-----------
  int Size(SNode<E>* head);  //find the number of nodes
  void Print();   //print the linked list
  SNode<E>* getHead(); //getter for the head private variable
  void mergeLists(SLinkedList<E>& list); //merge two linked lists
  void reverse(SNode<E>* current); //reverses a list
  //-----------------
 private:
  SNode<E>* head;  // head of the list
  void remove(SNode<E>* v);
};

template <typename E>
SLinkedList<E>::SLinkedList()  // constructor
    : head(NULL) {}

template <typename E>
bool SLinkedList<E>::empty() const {  // is list empty?
  return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {  // return front element
  return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {  // destructor
  while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {  // add to front of list
  SNode<E>* v = new SNode<E>;                // create new node
  v->elem = e;                               // store data
  v->next = head;                            // head now follows v
  head = v;                                  // v is now the head
}

template <typename E>
SNode<E>* SLinkedList<E>::getHead() {  // get head
  return head;
}
template <typename E>
void SLinkedList<E>::removeFront() {  // remove front item
  if (head == NULL) return;
  SNode<E>* old = head;  // save current head
  head = old->next;      // skip over old head
  delete old;            // delete the old head
}

template <typename E>
int SLinkedList<E>::Size(SNode<E>* head){
  if (head == NULL){
      return 0;
  }
  return 1 + Size(head->next);
}

template <typename E>
void SLinkedList<E>::Print(){ //print the linked list
    static SNode<E>* temp = head; //starting pointer
    if (temp == NULL){  //the temp goes out of bounds reset it back to head at the end
        temp = head; 
    }
    else if (temp->next == NULL){ //if it is the last element
        cout << temp->elem  << endl; //print it
        temp = NULL; //reset temp for above if statement
        return; 
    }
    cout << temp->elem << "->"; //print normally
    temp = temp->next; 
    Print(); 
}


template <typename E>
void SLinkedList<E>::mergeLists(SLinkedList<E>& list){
    SNode<E>* temp = head;
    while(temp->next != NULL){  //teleports us to the end of the linked list 
        temp = temp->next;  
    }
    temp->next = list.getHead(); //sets the last node to the head of the second list
    list.head = NULL;//remove list head since it is no longer the head of the merged lists
}

template <typename E>
void SLinkedList<E>::reverse(SNode<E>* current){ //reverses the linked list
    if (current->next == NULL){   //if you are at the last element
        head = current; //make the head the last element
        return;
    }
    reverse(current->next); //go to the last element
    current->next->next = current; //swaps the two nodes
    current->next = NULL; 
}

int main() {
    SLinkedList<std::string> sll;
    sll.addFront("four");
    sll.addFront("three");
    sll.addFront("two");
    sll.addFront("one");
    int n = sll.Size(sll.getHead());
    SLinkedList<std::string> sll2; 
    sll2.addFront("seven");
    sll2.addFront("six");
    sll2.addFront("five");
    int n2 = sll2.Size(sll2.getHead());
    cout << "List 1 has " << n << " nodes:" << endl;
    sll.Print();
    cout << "List 3 has " << n2 << " nodes:" << endl;
    sll2.Print();
    sll.mergeLists(sll2); 
    n = sll.Size(sll.getHead());
    cout << "After appending list 2 to list 1, list 1 has " << n << " nodes:" << endl;
    sll.Print();
    sll.reverse(sll.getHead());
    sll.Print();

}

