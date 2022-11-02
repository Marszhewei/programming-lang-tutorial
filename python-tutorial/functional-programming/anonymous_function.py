# get square for all elements
print(list(map(lambda x: x * x, [1, 2, 3, 4, 5, 6, 7, 8, 9])))

f = lambda x: x * x
print(f(5))


# as return val
def build(x, y):
    return lambda: x * x + y * y


def main():
    f = build(1, 2)
    print(f())


if __name__ == '__main__':
    main()