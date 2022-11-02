from collections.abc import Iterator
from functools import reduce


# function can be variable?
my_abs = abs
print(my_abs(-10))


def add(x, y, func):
    return func(x) + func(y)


def square(x):
    return x * x

def sub(x, y):
    return x - y


def cat(x, y):
    return x * 10 + y


def str2int(s):
    def cat(x, y):
        return x * 10 + y
    
    def char2num(x):
        return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[x]
    return reduce(cat, map(char2num, s))


# answer the questions
# first character to upper case and others to lower case
def normalize(name):
    s = name[0].upper()
    s += name[1:].lower()
    return s


# multi all elements
def prod(l):
    def multi(x, y):
        return x * y
    return reduce(multi, l)


# string to float
def str2float(s):
    def cat_integer(x, y):
        return x * 10 + y
    def char2num(x):
        return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[x]
    (s1, s2) = s.split('.')
    res = reduce(cat_integer, map(char2num, s1))
    res += reduce(cat_integer, map(char2num, s2)) / pow(10, len(s2))
    return res


# filter the odd number
def is_odd(n):
    return 1 == n % 2


# filter the empty str
def not_empty(s):
    return s and s.strip()


# this is a generator 
def _odd_iter():
    n = 1
    while True:
        n = n + 2
        yield n


def _not_divisible(n):
    return lambda x: x % n > 0


def primes():
    yield 2
    it = _odd_iter()
    while True:
        n = next(it)
        yield n
        it = filter(_not_divisible(n), it)

    
# answer the question
def is_palindrome(n):
    return str(n) == str(n)[::-1]


# sorted (answer the question)
def by_name(t):
    return t[0]


def main():
    res = add(10, -20, abs)
    print(res)

    res = map(square, [1, 2, 3])
    print(isinstance(res, Iterator))
    print(res)
    print(list(res))

    # all int elements to str?
    print(list(map(str, [1, 2, 3, 4])))

    # reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)
    print(reduce(sub, [10, 1, 2, 3]))

    # [1, 2, 3, 4] => 1234?
    print(reduce(cat, [1, 2, 3, 4]))

    # string to int
    print(str2int('7539'))

    # answer questions
    l1 = ['adam', 'LISA', 'barT']
    l2 = list(map(normalize, l1))
    print(l2)

    print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))

    print('str2float(\'123.456\') =', str2float('123.456'))


    # filter
    print(list(filter(is_odd, [1, 2, 3, 4, 5, 6])))
    print(list(filter(not_empty, ['A', '', None, 'B', 'C', '  '])))
    # primes
    for n in primes():
        if n < 20:
            print(n)
        else:
            break

    output = filter(is_palindrome, range(1, 1000))
    print(list(output))


    # sorted
    res = sorted([36, 5, -12, 9, -21], key=abs)
    print(res)
    res = sorted(['bob', 'bad', 'Zoo', 'Credit'], key=str.lower)
    print(res)
    # reverse
    res = sorted(['bob', 'bad', 'Zoo', 'Credit'], key=str.lower, reverse=True)
    print(res)

    l = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]
    res = sorted(l, key=by_name, reverse=True)
    print(res)
    

if __name__ == '__main__':
    main()