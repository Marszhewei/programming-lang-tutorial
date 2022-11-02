try:
    from collections.abc import Iterable
    from collections.abc import Iterator
except ImportError:
    from collections import Iterable
    from collections import Iterator


# dict iter
d = {'a': 1, 'b': 2, 'c': 3}
for key in d.keys():
    print(key)
for val in d.values():
    print(val)
for (key, val) in d.items():
    print(key, val)

# string iter
for ch in 'abc':
    print(ch)

print(isinstance('abc', Iterable))
print(isinstance((1, 2, 3), Iterable))
print(isinstance(['a', 'b'], Iterable))
print(isinstance(123, Iterable))

# get index of list/tuple/string...
for idx, val in enumerate(['a', 'b', 'c']):
    print(idx, val)

# get tuple from list...
for (x, y) in [(1, 2), (1, 3), (1, 4)]:
    print(x, y)

# can use next() to generate a new element called iterator
print(isinstance((x for x in range(10)), Iterator))
print(isinstance([], Iterator))

# list string dict is iterable but is not iterator
# we can use iter()
print(isinstance(iter([]), Iterator))
print(isinstance(iter('abc'), Iterator))
