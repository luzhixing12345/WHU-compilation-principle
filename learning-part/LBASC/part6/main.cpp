/*
 *Copyright (c) 2022 All rights reserved
 *@description: the main function
 *@author: Zhixing Lu
 *@date: 2022-04-06
 *@email: luzhixing12345@163.com
 *@Github: luzhixing12345
*/


#include "interpreter.h"
#include "lexer.h"

int main() {
    std::string statement = "1 + 2 * 3 + 4 * 5";
    lexer lexer_(statement);
    interpreter interpreter_(statement, &lexer_);
    std::cout << interpreter_.expr() << std::endl;
    return 0;
}