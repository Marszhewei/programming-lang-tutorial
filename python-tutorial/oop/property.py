#!/usr/bin/env python3
# -*- coding: utf-8 -*-


class Student(object):
    def get_score(self):
        return self.__score
         
    def set_score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self.__score = value

    
class Student_(object):
    def __init__(self, name):
        self.__name = name

    @property
    def score(self):
        return self.__score

    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self.__score = value

    @property
    def name(self):
        return self.__name


def main():
    stu = Student()
    stu.set_score(97)
    print(stu.get_score())

    stu_ = Student_('jack')
    stu_.score = 20
    print(stu_.score)
    print(stu_.name)


if __name__ == '__main__':
    main()