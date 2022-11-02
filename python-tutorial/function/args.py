def square(x):
    return x * x


def power(x, n=2):
    s = 1
    while n > 0:
        s *= x
        n -= 1
    return s


def enroll(name, gender, age=6, city="xi'an"):
    print(name, gender, age, city)


def add_end(l=[]):
    l.append('NED')
    return l


def fix_add_end(l=None):
    if l is None:
        l = []
    l.append('END')
    return l


# variable parameter
def calc_square_sum(*paras):
    s = 0
    for num in paras:
        s += (num * num)
    return s


def person(name, age, **kw):
    if 'city' in kw:
        pass
    if 'job' in kw:
        pass
    print('name:', name, 'age:', age, 'others:', kw)


# limit keywords parameter
def limit_person(name, age, *, city="xi'an", job):
    print(name, age, city, job)


def multi_func(argc, *argvs, **kw):
    print('this is argc:', argc)
    for argv in argvs:
        print(argv, end=' ')
    print()
    for key, val in kw.items():
        print(key, val)


def main():
    print(square(2))
    print(square(15))

    print(power(2, 3))
    print(power(3, 2))

    enroll('jack', 'M', 7)
    enroll('julia', 'F', city='xianyang')

    l = add_end([1, 2, 3])
    print(l)
    # default arguments must point to immutable objects
    l = add_end()
    print(l)
    l = add_end()
    print(l)
    # fix this bug
    l = fix_add_end()
    print(l)
    l = fix_add_end()
    print(l)

    res = calc_square_sum(1, 2, 3, 4)
    print(res)
    res = calc_square_sum()
    print(res)
    # if you want to use variable parameter function for tuple or list
    t = (1, 2, 3)
    res = calc_square_sum(*t)
    print(res)

    # keywords parameter
    extra = {'city': "xi'an", 'job': 'Engineer'}
    res = person('jack', 24, city=extra['city'], job=extra['job'])
    print(res)

    # limit keywords parameter
    res = limit_person('julia', 23, job='teacher')
    print(res)

    argc = 4
    argvs = ('argvs1', 'argvs2', 'argvs3')
    multi_func(argc, *argvs, kw1='kwone', kw2='kwtwo')


if __name__ == '__main__':
    main()