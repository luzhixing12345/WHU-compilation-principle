/*
 *Copyright (c) 2022 All rights reserved
 *@description: the main function
 *@author: Zhixing Lu
 *@date: 2022-04-06
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/

#include <windows.h>
#include "interpreter.h"
#include "lexer.h"

int main() {
    SetConsoleOutputCP(65001);
    std::string statement;
    int correctness = 0;
    int cnt = 1;
    while (1) {
        printf("calc> ");
        std::getline(std::cin, statement);
        std::cout<<statement<<std::endl;
        if (statement=="END")break;
        lexer lexer_(statement);
        interpreter interpreter_(&lexer_);   
        int answer = interpreter_.expr();
        printf("output = %d", answer);
        if (answer == cnt) {
            std::cout<<" (\u2714)\n";
            correctness++;
        } else {
            std::cout<<" (\u2717)\n";
        }
        cnt++;
    }
    printf("\n%d/%d\n",correctness,cnt-1);

    return 0;
}