#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def fn(self, name='jack'):
    print('hello, %s.' % name)


Say = type('Say', (object,), dict(hello=fn))
s = Say()
s.hello('tom')
print(type(s))
print(type(Say))


class ListMetaclass(type):
    def __new__(cls, name, bases, attrs):
        attrs['add'] = lambda self, value: self.append(value)
        return type.__new__(cls, name, bases, attrs)

    
class MyList(list, metaclass=ListMetaclass):
    pass


def main():
    l = MyList()
    l.add(1)
    print(l)


if __name__ == '__main__':
    main()