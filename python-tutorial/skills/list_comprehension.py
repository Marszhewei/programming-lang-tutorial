import os


# create [1, 2, 3, 4, 5, 6, 7, 8, 9]
res = list(range(1, 10))
print(res)

# create [1x1, 2x2, 3x3, 4x4, ...]
# use loop
res = []
for x in range(1, 10):
    res.append(x * x)
print(res)
# use list comprehension
res = [x * x for x in range(1, 10)]
print(res)
# just for even number
res = [x * x for x in range(1, 10) if 0 == x % 2]
print(res)

# full array
res = [m + n for m in 'ABC' for n in 'XYZ']
print(res)

# list all files
res = [x for x in os.listdir('.')]
print(res)

# if elif else ?
l = [1, 2, 3, 4, 5]
res = [x * 2 if 1 == x % 2 else x for x in l]
print(res)

# answer the qustion
l1 = ['hello', 'world', 18, 'apple', None]
res = [x for x in l1 if isinstance(x, str)]
print(res)