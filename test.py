import pytest
import glob
import re
import os
import importlib
from pprint import pprint


def get_Solution(idx):
    pat = rf'./solutions/[[]{idx}[]]*.py'
    files = glob.glob(pat)
    test_module = files[0][:-3].split('\\')[-1]
    test_module = f'.solutions.{test_module}'
    print(__package__)
    test_module = importlib.import_module(name=test_module, package=__package__)
    print(test_module)
    solution = test_module.Solution()



if __name__ == '__main__':
    os.chdir('./solutions-to-leetcode-cn')

    from argparse import ArgumentParser
    parser = ArgumentParser(prog="A parser for test basic functions")
    parser.add_argument('--idx', type=str, default=None)
    args = parser.parse_args()

    if args.idx is not None:
        get_Solution(args.idx)
    
    else:
        print('No idx is specified!')