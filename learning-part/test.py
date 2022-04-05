'''
*Copyright (c) 2022 All rights reserved
*@description: to test the correctness of the code
*@author: Zhixing Lu
*@date: 2022-04-04
*@email: luzhixing12345@163.com
*@Github: luzhixing12345
'''

import argparse
import os



if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('part',nargs='?',help='the part of the code to be tested')
    parser.add_argument('--compile','-c',action='store_true',help='compile the cpp code')
    args = parser.parse_args()
    
    test_example = 'LBASC/'+args.part+'/test-example.txt'
    test_file = 'LBASC/'+args.part+'/calc.py'
    
    gcc_part = ['part3','part6']
    if args.compile:
        if args.part == 'part3':
            os.system(f'g++ LBASC\\{args.part}\\main.cpp LBASC\\{args.part}\\interpreter.cpp -o LBASC\\{args.part}\\main.exe ')
        elif args.part == 'part6':
            os.system(f'g++ LBASC\\{args.part}\\main.cpp LBASC\\{args.part}\\interpreter.cpp LBASC\\{args.part}\\lexer.cpp -o LBASC\\{args.part}\\main.exe ')
            os.system(f'LBASC\\{args.part}\\main.exe < '+test_example)
    else :   
        if args.part in gcc_part:
            os.system(f'LBASC\\{args.part}\\main.exe < '+test_example)
        else:
            os.system('python '+test_file+' < '+test_example)
    print('over')
    