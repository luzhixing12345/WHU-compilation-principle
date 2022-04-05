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
    parser.add_argument('part',nargs='?',default='part1',help='the part of the code to be tested')
    parser.add_argument('--compile','-c',action='store_true',help='compile the cpp code')
    args = parser.parse_args()
    
    test_example = 'LBASC/'+args.part+'/test-example.txt'
    test_file = 'LBASC/'+args.part+'/calc.py'
    if args.compile:
        os.system('g++ LBASC\\part3\\main.cpp LBASC\\part3\\interpreter.cpp -o LBASC\\part3\\main.exe ')
        os.system('LBASC\\part3\\main.exe < '+test_example)
    else :   
        if args.part == "part3":
            os.system('LBASC\\part3\\main.exe < '+test_example)
        else:
            os.system('python '+test_file+' < '+test_example)
    print('over')
    