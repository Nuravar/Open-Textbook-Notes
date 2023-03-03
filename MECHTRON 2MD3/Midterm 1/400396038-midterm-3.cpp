#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <deque>



class Deque {
    private:
        int size; 
        std::vector<std::string> ADT;
    public:
        Deque(int n){ //(a)
            size = n;
            ADT.reserve(size);
        }
        ~Deque(){}
        void insertFront(std::string e);
        void insertBack(std::string e);
        void eraseFront();
        void eraseBack();
        std::string front();
        std::string back();
        int size();
        bool empty();
};

void Deque::insertFront(std::string e){

}
void Deque::insertBack(std::string e){

}
void Deque::eraseFront(){

}
void Deque::eraseBack(){
    if(!empty()){

    }
}
std::string Deque::front(){
    if(!empty()){
        return ADT.front();
    } else {
        return "error: empty deque";
    }
}
std::string Deque::back(){
    if(!empty()){
        return ADT.back();
    } else {
        return "error: empty deque";
    }
}
int Deque::size(){
    return ADT.size();
}
bool Deque::empty(){
    return ADT.empty();
}
