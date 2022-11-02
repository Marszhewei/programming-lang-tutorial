#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# _variable (you can get but can't set)
# __variable (you can't get and set), but can use _calss-name__variable


class Student(object):
    def __init__(self, name, score):
        # private variable
        self.__name = name
        self.__score = score

    def set_score(self, score):
        self.__score = score
    
    def set_name(self, name):
        self.__name = name

    def get_score(self):
        return self.__score

    def get_score(self):
        return self.__name

    def print_score(self):
        print('%s : %s' % (self.__name, self.__score))

    def get_grade(self):
        if self.__score >= 90:
            return 'A'
        elif self.__score >= 60:
            return 'B'
        else:
            return 'C'


def main():
    stu = Student('jack', 97)
    stu.print_score()
    print('grade level:', stu.get_grade())


if __name__ == '__main__':
    main()
