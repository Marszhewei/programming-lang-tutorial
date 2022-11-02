#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import types


print(type(123))
print(type('asd'))
print(type(None))
print(type(abs))

print(type('asd') == type('123'))
print(type('asd') is str)

# check for function
def fn():
    pass

print(type(fn) == types.FunctionType)
print(type(abs) == types.BuiltinFunctionType)

# use isinstance to check class type
print(isinstance((1, 2, 3), (list, tuple)))
print('abd'.__len__())
print(len('abd'))

# use dir to check the methods of type
print(dir('avd'))


# getattr() setattr() hasattr()
class MyObject(object):
    def __init__(self):
        self.x = 9

    def power(self):
        return self.x * self.x

def main():
    obj = MyObject()
    print(hasattr(obj, 'x'))
    print(obj.x)
    setattr(obj, 'y', 19)
    print(hasattr(obj, 'y'))
    print(getattr(obj, 'y'))
    print(getattr(obj, 'z', 404)) # set default return value

    print(getattr(obj, 'power'))


if __name__ == '__main__':
    main()