//
//  main.cpp
//  
//  Calculator
//  Created by Matanel Ohayon on 03/05/2026.
//

#include <iostream>
#include "calculator.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    Calculator cal;
    cal.read_input();
    cal.print_vec();
    cal.parser();
    cal.print_result();
    
    return 0;
}
