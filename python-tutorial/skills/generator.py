from collections.abc import Iterable
from operator import ne

from numpy import isin


# use () creating generator
l = [x * x for x in range(1, 11)]
print(l)
g = (x * x for x in range(1, 11))
print(g)
# but how to get the elements of generator
print(next(g))
# it's so cumbersome, it's nice for generator can be itered
if isinstance(g, Iterable):
    for n in g:
        print(n)

# from function to generator
def fibonacci(max):
    n, a, b = 0, 0, 1
    while n < max:
        print(b, end=' ')
        a, b = b, a + b
        n += 1
    return a


def fibonacci_generator(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n += 1


def odd():
    print('step 1', end=' : ')
    yield 1
    print('step 2', end=' : ')
    yield(3)
    print('step 3', end=' : ')
    yield(5)


def main():
    fibonacci(5)
    print()
    f = fibonacci_generator(5)
    if isinstance(f, Iterable):
        for n in f:
            print(n, end=' ')
        print()
    if isinstance(odd(), Iterable):
        for n in odd():
            print(n)


if __name__ == '__main__':
    main()