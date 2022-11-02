# a lazy sum function
def lazy_sum(*args):
    def sum():
        sn = 0
        for n in args:
            sn += n
        return sn
    return sum


# just a example about cosure
def count():
    def f(j):
        def g():
            return j*j
        return g
    fs = []
    for i in range(1, 4):
        fs.append(f(i))
    return fs


def main():
    my_sum = lazy_sum(1, 3, 5, 7)
    print(my_sum())
    f1 = lazy_sum(1, 3, 5, 7)
    f2 = lazy_sum(1, 3, 5, 7)
    if f1 is f2:
        print('the same object')
    else:
        print('not the same object')

    f1, f2, f3 = count()
    print(f1())
    print(f2())
    print(f3())


if __name__ == '__main__':
    main() 