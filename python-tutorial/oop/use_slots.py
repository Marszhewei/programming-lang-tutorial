#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from types import MethodType


class Student(object):
    # def __init__(self, age) -> None:
    #     self.age = age
    # properties that restrict an instance, but it doesn't work for his childs
    __slots__ = ('name', 'age', 'set_age')


def set_age(self, age):
    self.age = age


def main():
    stu = Student()
    stu.name = 'jack'
    print(stu.name)
    # s1 = Student()
    # print(s1.name)  s1 don't have name
    
    # we also can bind a method to instance
    stu.set_age = MethodType(set_age, stu)
    stu.set_age(25)
    print(stu.age)

    # s2 = Student()
    # s2.set_age(27) s2 don't have this method
    Student.set_age = MethodType(set_age, Student)
    s3 = Student()
    s3.set_age(21)
    print(s3.age)
    # s3.score = 100


if __name__ == '__main__':
    main()