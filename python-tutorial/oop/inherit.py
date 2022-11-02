#!/usr/bin/env python3
# -*- coding: utf-8 -*-


class Animal(object):
    def run(self):
        print('Animal is running...')


class Dog(Animal):
    def run(self):
        print('Dog is running...')

    def bark(self):
        print('Dog is barking...')


class Cat(Animal):
    def run(self):
        print('Cat is running...')

    def eat(self):
        print('Cat is eating...')

    
class NotAnimal(object):
    def run(self):
        print('This guy can not run...')


def run_twice(animal):
    animal.run()
    animal.run()

    
def main():
    animal = Animal()
    animal.run()
    dog = Dog()
    dog.run()
    dog.bark()
    cat = Cat()
    cat.run()
    cat.eat()

    # polymorphism
    print(isinstance(animal, Animal))
    print(isinstance(cat, Cat))
    print(isinstance(dog, Dog))

    print(isinstance(cat, Animal))
    print(isinstance(dog, Animal))

    run_twice(dog)
    run_twice(cat)
    run_twice(NotAnimal())


if __name__ == '__main__':
    main()