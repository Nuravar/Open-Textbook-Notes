#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <ctype.h>
#include <sstream>
using namespace std;


class Stack { //stack class utlizing vector
private:
    vector<double> data;

public:
    void push(const double value) { //push function
        data.push_back(value);
    }

    double pop() { //pop function with a return
        double topper = data.back();
        data.pop_back();
        return topper;
    }

    double top() { //top function
        return data.back();
    }

    bool empty() const { //check if stack is empty
        return data.empty();
    }

    size_t size() const { //size of vector
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

RPNEvaluator::RPNEvaluator(string rpn_exp){ //constructor
    expression = rpn_exp;
}

bool RPNEvaluator::isNumber(string s){ //function to check if multi digit strings are numbers
    for( int i = 0; i < s.length(); i++ ) {
      if(s[0]=='-'){ //ignores negative signs if it is the first character
        continue;
      }
      if(s[i]!='.'){ //ignores decimal places
        if(!isdigit(s[i])) { //checks if each character in the string is a number
         return false;
        }
      } else {
        continue;
      }
      
   }
   return true;
}
bool RPNEvaluator::isOneUnit(string s){ //checks if the string is one unit long
    if(s.length()==1){
        return true;
    } else {
        return false;
    }
}

double RPNEvaluator::Evaluate(){
    istringstream iss(expression); //string string function that tokenizes/parses the input string by whitespace automatically into separate strings
    while (iss){ //checks if there is anymore tokens to be had
        string subs; //token container for each string
        if (iss >> subs){//iterator through the iss stringstream, acts as a boolean to check if it is finished and assined new variable
            if (subs!="+"&& subs!="-" && subs!="*" && subs !="/" && isNumber(subs)){ //checks if a item is a number and adds it to the stack
                //cout << subs << endl;
                rpn_stack.push(stod(subs)); //"-5" = -5
            } else { // else if it is an operator
                double num2,num1;
                if(rpn_stack.size()>=2){ //it checks if there are two items before assigning the top two variables in the stack for operations 
                    num2 = rpn_stack.pop();
                    num1 = rpn_stack.pop();
                } else { //if there are less than 2 items in the stack before an operation nothing can be calculatied
                    printf("Error: malformed expression");
                    return -1;
                }
                if(isOneUnit(subs)){ //checks if the operators are actually one unit long
                    switch (subs.at(0)){
                        case '+':
                            rpn_stack.push(num1+num2); //adds numbs
                            break;
                        case '-':
                            rpn_stack.push(num1-num2); //substracts
                            break;
                        case '*':
                            rpn_stack.push(num1*num2); //multiplies
                            break;
                        case '/':
                            rpn_stack.push(num1/num2); //divides
                            break;
                        default: //else if it is a one unit character that is not an operator it is not an expression
                            printf("Error: malformed expression");
                            return -1;
                            break;
                    }
                } else { //if it is some random multi digit character it returns error
                    printf("Error: malformed expression");
                    return -1;
                }
            }
        
        }
    }
    PrintStack(rpn_stack); //prints the last number in the stack/result
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
    string rpn_exp;
    std::cout << "Please enter an expression in RPN format: ";
    std::getline(std::cin, rpn_exp);
    RPNEvaluator rpn(rpn_exp);
    rpn.Evaluate();
    return EXIT_SUCCESS;
}


