//
//  calculator.cpp
//
//
//  Created by Matanel Ohayon on 03/05/2026.
//

#include "calculator.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

double Calculator::add(double a,double b){
    return a+b;
}
double Calculator::subtract(double a,double b){
    return a-b;
}
double Calculator::multiply(double a, double b){
    return a*b;
}
double Calculator::divide(double a, double b){
    if(b==0)
        throw std::runtime_error("Division by zero!");
    return a/b;
}


void Calculator::read_input(){
    
    //string input;
    cout<<"Enter equation:"<<endl;
    getline(cin,input);
    int size = (int)input.size();
    int par=0;
    int par_count =0;
    //bool in_num=false;
    //int neg=1;
    for(int i=0;i<size;i++){
        switch (input[i]) {
            case '(':{
                numop *tmp=new numop('(');
                vec.push_back(tmp);
                par++;
                continue;
            }
            case ')':{
                if(par==0)
                    throw std::runtime_error("Unmatch Parentheses!");
                numop *tmp=new numop(')');
                vec.push_back(tmp);
                par--;
                par_count++;
                continue;
            }
            case '+':{
                numop *tmp=new numop('+');
                vec.push_back(tmp);
                continue;
            }
            case '-':{
                numop *tmp=new numop('-');
                vec.push_back(tmp);
                continue;
            }
            case '*':{
                if(i==0 || input[i-1]=='(')
                    throw std::runtime_error("Invalid input!");
                numop *tmp=new numop('*');
                vec.push_back(tmp);
                continue;
            }
            case '/':{
                if(i==0 || input[i-1]=='(')
                    throw std::runtime_error("Invalid input!");
                numop *tmp=new numop('/');
                vec.push_back(tmp);
                continue;
            }
            case ' ': continue;
        }
        if(input[i]>='0' && input[i]<='9'&& i<size){
            
            
            int num=0;
            while(input[i]>='0' && input[i]<='9'){
                num=num*10;
                int digit = input[i]-'0';
                num=num+digit;
                i++;
            }
            i--;
            numop *tmp = new numop(num);
            vec.push_back(tmp);
            continue;
        }
        
        throw std::runtime_error("Invalid input!");
    }
    if(par != 0)
        throw std::runtime_error("Unmatched Parentheses!");
    
    
}

double Calculator::factor() {
    numop* token = vec[pos++];
    if (token->isNum()) return token->num;
    if (token->op == '(') {
        double result = expression();
        pos++; // Skip ')'
        return result;
    }
    return 0;
}

double Calculator::term() {
    double left = factor();
    while (pos < vec.size() && (vec[pos]->op == '*' || vec[pos]->op == '/')) {
        char op = vec[pos++]->op;
        double right = factor();
        left = calculate(left, right, op);
    }
    return left;
}

double Calculator::expression() {
    double left = term();
    while (pos < vec.size() && (vec[pos]->op == '+' || vec[pos]->op == '-')) {
        char op = vec[pos++]->op;
        double right = term();
        left = calculate(left, right, op);
    }
    return left;
}


double Calculator::parser() {
    pos = 0;
    result = expression();
    reset();
    return result;
}

double Calculator::calculate(double a, double b, char op){
    switch (op) {
        case '+':   return add(a, b);
        case '-':   return subtract(a, b);
        case '*':   return multiply(a, b);
        case '/':   return divide(a, b);
    }
    return 0;
    
}


void Calculator::print_vec(){
    if(vec.size()==0){
        cout<<"nothing to print"<<endl;
        return;
    }
    for(auto it = vec.begin();it!=vec.end();it++){
        if ((*it)->isNum()){
            cout<<(*it)->num<<endl;
        }
        else
            cout<<(*it)->op<<endl;
        
    }
}

void Calculator::print_result(){
    string res=input;
    res.append(" = ");
    string value = to_string(result);
    res.append(value);
    cout<<res<<endl;
    cout<<"the result is: "<<value<<endl;
}

void Calculator::reset(){
    for(auto v:vec) delete v;
    vec.clear();
}

Calculator::~Calculator() {
    for (auto p : vec) delete p;
}
