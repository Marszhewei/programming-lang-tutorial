import functools


# str to int (bin)
print(int('0011', base=2))

int2 = functools.partial(int, base=2)
print(int2('0010'))

def int16(x, base=16):
    return int(x, base)
print(int16('0xf'))

# use *args **kw
kw = { 'base': 2 }
print(int('10010', **kw))

max2 = functools.partial(max, 2)
print(max2(-2, 1, 0))

