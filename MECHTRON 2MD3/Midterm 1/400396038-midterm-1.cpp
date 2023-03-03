#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <ctype.h>
#include <sstream>
using namespace std;


class Stack {
private:
    vector<double> data;

public:
    void push(const double value) {
        data.push_back(value);
    }

    double pop() {
        double topper = data.back();
        data.pop_back();
        return topper;
    }

    double top() {
        return data.back();
    }

    double top() const {
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

class RPNEvaluator {
    private:
    string expression;
    Stack rpn_stack;
    public:
    //constructor
    RPNEvaluator(string rpn_exp);
    virtual ~RPNEvaluator() {};
    
    //Evaulate function
    double Evaluate();
    void PrintStack(Stack s);
    bool isNumber(string s);
    bool isOneUnit(string s);
};

RPNEvaluator::RPNEvaluator(string rpn_exp){
    expression = rpn_exp;
}

bool RPNEvaluator::isNumber(string s){
    for( int i = 0; i < s.length(); i++ ) {
      if(s[0]=='-'){
        continue;
      }
      if(s[i]!='.'){
        if(!isdigit(s[i])) {
         return false;
        }
      } else {
        continue;
      }
      
   }
   return true;
}
bool RPNEvaluator::isOneUnit(string s){
    if(s.length()==1){
        return true;
    } else {
        return false;
    }
}

double RPNEvaluator::Evaluate(){
    istringstream iss(expression); //iss = expression separated by the spaces
    while (iss){
        string subs;
        if (iss >> subs){ 
            if (subs!="+"&& subs!="-" && subs!="*" && subs !="/" && isNumber(subs)){
                cout << subs << endl;
                rpn_stack.push(stod(subs)); //"-5" = -5
            } else {
                double num2,num1;
                if(rpn_stack.size()>=2){
                    num2 = rpn_stack.pop();
                    num1 = rpn_stack.pop();
                }
                if(isOneUnit(subs)){ 
                    switch (subs.at(0)){
                        case '+':
                            rpn_stack.push(num1+num2);
                            break;
                        case '-':
                            rpn_stack.push(num1-num2);
                            break;
                        case '*':
                            rpn_stack.push(num1*num2);
                            break;
                        case '/':
                            rpn_stack.push(num1/num2);
                            break;
                        default:
                            printf("Error: malformed expression");
                            return -1;
                            break;
                    }
                } else {
                    printf("Error: malformed expression");
                    return -1;
                }
            }
        
        }
    }
    PrintStack(rpn_stack);
    return rpn_stack.top();
}

void RPNEvaluator::PrintStack(Stack s){
    if (s.empty())
        return;

    double x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

int main(){
    string rpn_exp = "5  2 + 8 3 - * 4 /";
    // std::cout << "Please enter an expression in RPN format: ";
    //std::getline(std::cin, rpn_exp);
    RPNEvaluator rpn(rpn_exp);
    rpn.Evaluate();
    return EXIT_SUCCESS;
}

