# recursion


from more_itertools import tail


def factor(n):
    if 1 == n:
        return 1
    else:
        return n * factor(n - 1)


# tail recursion
def tail_factor(n):
    return fact_iter(n, 1)


def fact_iter(n, p):
    if 1 == n:
        return 1
    else:
        return fact_iter(n - 1, n * p)


def hanoi(n, a, b, c):
    if 1 == n:
        print(a + ' -> ' + c)
    else:
        hanoi(n - 1, a, c, b)
        hanoi(1, a, b, c)
        hanoi(n - 1, b, a, c)


def main():
    print(factor(4))
    print(tail_factor(4))

    hanoi(3, 'A', 'B', 'C')


if __name__ == '__main__':
    main()