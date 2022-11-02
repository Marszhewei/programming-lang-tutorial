#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''a test module'''

__author__ = 'fetch150zy'

import sys


# private
def _private_1(name):
    return 'Hello, %s' % name


def _private_2(name):
    return 'Hi, %s' % name


# public
def greeting(name):
    if len(name) > 3:
        return _private_1(name)
    else:
        return _private_2(name)


def main():
    args = sys.argv
    if len(args) == 0:
        print('Usage: python module.py ...')
    else:
        for item in args[1:]:
            print(item)
    

if __name__ == '__main__':
    main()