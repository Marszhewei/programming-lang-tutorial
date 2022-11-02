#!/usr/bin/env python3
# -*- coding: utf-8 -*-


class Student(object):
    name = 'mars'
    age = 18
    def __init__(self, name, age) -> None:
        self.name = name
        self.age = age

def main():
    stu = Student('jack', 20)
    print(stu.name, stu.age)
    print(Student.name, Student.age)


if __name__ == '__main__':
    main()