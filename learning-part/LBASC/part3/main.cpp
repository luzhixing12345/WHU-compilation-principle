/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function for the interpreter
 *@author: Zhixing Lu
 *@date: 2022-04-04
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "interpreter.h"

int main() {

    std::string statement = "";
    while (1) {
        printf("calc> ");
        std::getline(std::cin, statement);
        std::cout<<statement<<std::endl;
        if (statement=="END")break;
        int answer = expr(statement);
        printf("output = %d\n", answer);
    }
    return 0;
}
