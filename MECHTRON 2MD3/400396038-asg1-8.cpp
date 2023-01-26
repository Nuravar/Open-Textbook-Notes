#include <iostream> 

template <typename t1, typename t2>   

class Pair{
    public:
        t1 num1;
        t2 num2;

        Pair(t1 num1, t2 num2) : num1(num1), num2(num2) {}

        void print(){
            std::cout << "<" << num1 << ", " << num2 << ">" << std::endl;
        }
};

int main(){


    Pair<int, std::string> p1(1, "7.3");
    p1.print();

    Pair<std::string, double> p2("hello", 7.7);
    p2.print();

    Pair<float, long> p3(1.2, 777777773);
    p3.print();

   return 0; 

}