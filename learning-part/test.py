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
    parser.add_argument('--output','-o',action='store_true',help='output the result of the test')
    args = parser.parse_args()
    
    test_example = 'learning-part/LBASC/'+args.part+'/test-example.txt'
    test_file = 'learning-part/LBASC/'+args.part+'/calc.py'
    output_file = 'learning-part/LBASC/'+args.part+'/output.txt'
    if args.output:
        os.system('python '+test_file+' < '+test_example+' > '+output_file)
    else:
        os.system('python '+test_file+' < '+test_example)
    print('over')
    