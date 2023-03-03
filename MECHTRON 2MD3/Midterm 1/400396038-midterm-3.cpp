#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>    // std::rotate



class Deque {
    private:
        int n; //size
        int f; //front
        int r; //rear
        int currentN;
        std::vector<std::string> ADT; //circular vector
    public:
        Deque(int size){
            n = size;
            f = 0;
            r = 0;
            currentN = 0;
            ADT.reserve(size); 
        }
        void insertFront(std::string e);
        void insertBack(std::string e);
        void eraseFront();
        void eraseBack();
        void front();
        void back();
        void size();
        void empty();
};

void insertFront(std::string e){

}
void insertBack(std::string e){

}
void eraseFront(){

}
void eraseBack(){

}
void front(){

}
void back(){

}
void size(){
    return currentN;
}
void empty(){
    return currentN == 0;
}



int main(){
    Deque deque(5); // testing (A)
    deque.insertBack("2");
    deque.insertBack("3");
    deque.insertBack("4");
    deque.insertBack("5"); 
    deque.insertFront("1");
    // deque.printVector(); // testing insert front (B) and back (C)
    deque.insertBack("6");
    // deque.printVector(); // testing circular insert back (C)
    deque.insertFront("7");
    // deque.printVector(); // testing circular insert front (D)
    deque.eraseBack();
    deque.eraseBack();
    deque.eraseBack();
    deque.eraseBack();
    deque.eraseFront();
    deque.eraseFront();
    std::string test1 = deque.front();
    std::string test2 = deque.back();
    // std::cout << test1 << "|" << test2 <<std::endl; //testing error for front and back
    // deque.printVector(); //testing erase back (E) and front (F)
    deque.insertBack("2");
    deque.insertBack("3");
    deque.insertBack("4");
    deque.insertBack("5"); 
    deque.insertFront("1");

}