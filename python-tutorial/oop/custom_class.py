#!/usr/bin/env python3
# -*- coding: utf-8 -*-


class Student(object):
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return 'Student object (name: %s)' % self.name

    def __getattr__(self, attr):
        if attr == 'age':
            return 18
        raise AttributeError('\'Student\' object has no attribute \'%s\'' % attr)

    def __call__(self):
        print('My name is %s.' % self.name)

    # __repr__ is for debuger
    __repr__ = __str__


# a iter class?
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1

    def __iter__(self):
        return self

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        if self.a > 100:
            raise StopIteration()
        return self.a

    def __getitem__(self, n):
        if isinstance(n, int):
            a, b = 1, 1
            for x in range(n):
                a, b = b, a + b
            return a
        if isinstance(n, slice):
            start = n.start
            stop = n.stop
            if start is None:
                start = 0
            a, b = 1, 1
            l = []
            for x in range(stop):
                if x >= start:
                    l.append(a)
                a, b = b, a + b
            return l


def main():
    s = Student('jack')
    # print(s)
    # more beautiful print?
    print(s)
    # __getattr__()
    print(s.age)
    # __call__()
    s()
    print(callable(s))
    print(callable(max))
    print(callable([1, 2]))

    # __iter__(), __next__()
    for n in Fib():
        print(n, end=' ')
    print()
    # use index like list
    print(Fib()[2])
    # use slice?
    print(Fib()[0:4])


if __name__ == '__main__':
    main()