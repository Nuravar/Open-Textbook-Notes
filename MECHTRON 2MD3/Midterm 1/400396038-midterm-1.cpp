#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <ctype.h>
#include <sstream>
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
        double pop(){
            double top = ADT.top();
            ADT.pop();
            //cout << top << endl;
            return top;
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
    RPNEvaluator(string rpn_exp);
    virtual ~RPNEvaluator() {};
    
    //Evaulate function
    double Evaluate();
    void PrintStack(Stack s);
    vector<string> split(string str);
    bool isNum(string exp);
};

bool RPNEvaluator::isNum(string exp){
    for(int i =0;i<exp.length()-1;i++){
        
    }
}

RPNEvaluator::RPNEvaluator(string rpn_exp){
    expression = rpn_exp;
}

/* 
    Format for solving question 1
    Step 1: create a stack for all numbers, heere it is rpn_stack which holds doubles
    Step 2: if the item extracted from the string is a number push to the stack but if it is a operator pop last two numbers, evaluate 
    the expression, and push the resulting number
    Step 3: continue until you are at the end of the string
    Step 4: if you are at the end of the string you should have only one number left (ie: size = 1) and pop/return the last number
    Step 5: if size is not 1 at the end or if the operators are not correct in the switch statement return -1 and print "Error: malformed expression"
*/
double RPNEvaluator::Evaluate(){
    //remove spaces
    // for(int i =0;i<expression.length()-1;i++){
    //     if(expression[i]==' '){
    //         expression.erase(i,1);
    //     }
    // }
    vector<string> exp = split(expression);
    //check if stack works
    for(int i =0;i<exp.size();i++){
        //double num = atof(expression[i]);
        if (exp[i] != "+", "-", "*", "/" && isdigit(exp[i])){
            rpn_stack.push((double)expression[i] - '0');
        } else {
            double num2 = rpn_stack.pop();
            double num1 = rpn_stack.pop();
            switch (expression[i]){
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
        }
    }
    PrintStack(rpn_stack);
    return rpn_stack.top();
}

void RPNEvaluator::PrintStack(Stack s){
    if (s.isEmpty())
        return;

    double x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

vector<string> RPNEvaluator::split(string str){
    vector<string> equation;
    stringstream ss(str);
    string token;
    while(getline(ss, token, ' ')) { 
    equation.push_back(token); 
    } 
    return equation; 
}

int main(){
    string rpn_exp = "5 2 + 8 3 - * 4 /";
    // std::cout << "Please enter an expression in RPN format: ";
    //std::getline(std::cin, rpn_exp);
    RPNEvaluator rpn(rpn_exp);
    rpn.Evaluate();
    return EXIT_SUCCESS;
}