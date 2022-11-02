#!/usr/bin/env python3
# -*- coding: utf-8 -*-


from enum import Enum, unique


Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'))
for name, member in Month.__members__.items():
    print(name, '=>', member, ',', member.value)


# check for no duplicates
@unique
class Weekday(Enum):
    Sun = 0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6


def main():
    print(Weekday.Mon)
    print(Weekday.Mon.value)
    print(Weekday(0))
    print(Weekday['Wed'])

    for name, member in Weekday.__members__.items():
        print(name, '=>', member, ':', member.value)


if __name__ == '__main__':
    main()