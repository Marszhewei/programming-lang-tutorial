import math


# define my function
from typing import Type


def my_abs(x):
    if not isinstance(x, (int, float)):
        raise TypeError("bad operand type")
    if x >= 0:
        return x
    else:
        return -x


# empty function
def nop():
    pass


# return multiple values
def move(pos_x, pos_y, move_step, move_angle=0):
    nx = pos_x + move_step * math.cos(move_angle)
    ny = pos_y + move_step * math.sin(move_angle)
    return (nx, ny)


def main():
    print(my_abs(-10))
    print(my_abs(1))
    # my_abs("a")
    # do nothing
    nop()
    # return multiple values
    x, y = move(100, 100, 60, math.pi / 6)
    print(x, y)


if __name__ == "__main__":
    main()
