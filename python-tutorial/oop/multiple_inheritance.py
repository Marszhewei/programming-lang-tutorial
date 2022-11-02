#!/usr/bin/env python3
# -*- coding: utf-8 -*-


# mixln
class Animal(object):
    pass


class Runnable(object):
    def run(self):
        print('Running...')


class Flyable(object):
    def fly(self):
        print('Flying...')


class Mammal(Animal):
    pass


class Bird(Animal):
    pass


class Dog(Mammal, Runnable):
    pass


class Bat(Mammal):
    pass


class Parrot(Bird, Flyable):
    pass


class Ostrich(Bird):
    pass


def main():
    dog = Dog()
    dog.run()
    parrot = Parrot()
    parrot.fly()


if __name__ == '__main__':
    main()
