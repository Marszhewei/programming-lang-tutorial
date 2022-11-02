# decorator
def log(func):
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper


# function as variable
@log # now = log(now)
def now():
    print('2022-10-19')


def main():
    f = now
    f()
    # get function name?
    print(now.__name__, f.__name__)


if __name__ == '__main__':
    main()