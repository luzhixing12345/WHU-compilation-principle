/*
 *Copyright (c) 2022 All rights reserved
 *@description: main function for the interpreter
 *@author: Zhixing Lu
 *@date: 2022-04-04
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include "interpreter.h"
#include <windows.h>

int main() {
    //SetConsoleOutputCP(65001); utf-8
    std::string statement = "";
    int correctness = 0;
    int cnt = 1;
    while (1) {
        printf("calc> ");
        std::getline(std::cin, statement);
        std::cout<<statement<<std::endl;
        if (statement=="END")break;
        int answer = expr(statement);
        printf("output = %d", answer);
        if (answer == cnt) {
            std::cout<<" (\u2714)\n";
            correctness++;
        }
        cnt++;
    }
    printf("\n%d/%d\n",correctness,cnt-1);
    return 0;
}
