#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Stack {
    private:
        stack<double> ADT;
    public:
        void push(double val){
            ADT.push(val);
        }
        double popTwo(){
            double top = ADT.top();
            ADT.pop();
            double top2 = ADT.top();
            ADT.pop();
            return top, top2;
        }
        double top() {
            double top = ADT.top();
            return top;
        }
        bool isEmpty(){
            return ADT.empty();
        }
        int size(){
            return ADT.size();
        }
};

class RPNEvaluator {
    private:
    string expression;
    double result;
    Stack rpn_stack;
    public:
    //constructor
    RPNEvaluator(string rpn_exp){
        expression = rpn_exp;
    }
    ~RPNEvaluator();

    /* 
    Format for solving question 1
    Step 1: create a stack for all numbers, heere it is rpn_stack which holds doubles
    Step 2: if the item extracted from the string is a number push to the stack but if it is a operator pop last two numbers, evaluate 
    the expression, and push the resulting number
    Step 3: continue until you are at the end of the string
    Step 4: if you are at the end of the string you should have only one number left (ie: size = 1) and pop/return the last number
    Step 5: if size is not 1 at the end or if the operators are not correct in the switch statement return -1 and print "Error: malformed expression"
    */
    //Evaulate function
    double Evaluate(expression){

    }
    

};

