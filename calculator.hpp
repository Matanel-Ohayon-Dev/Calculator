//
//  calculator.hpp
//  
//
//  Created by Matanel Ohayon on 03/05/2026.
//

#ifndef calculator_hpp
#define calculator_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class numop{
public:
    double num;
    char op;
    bool isnum;
    numop(int x):num(x), op(0),isnum(true){};
    numop(char x): num(0),op(x),isnum(false){};
    bool isNum(){return isnum;};
    
};



class Calculator {
    vector<numop*> vec;
    int pos;
    string input;
    double result;
    
public:
    Calculator(){pos=0; result=0;};      // constructor
    
    void read_input();
    double parser();
    double factor();
    double term();
    double expression();
    double calculate(double a, double b, char op);
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    void print_vec();
    void print_result();
    void reset();
    ~Calculator();
};








#endif /* calculator_hpp */
