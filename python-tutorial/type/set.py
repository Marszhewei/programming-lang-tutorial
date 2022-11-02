s = set([1, 2, 3])
print(s)

# you can use set to delete the same elements
l = [1, 2, 3, 3, 4]
s = set(l)
print(l, s)

# add elements
s.add(-1)
s.add(-1)
print(s)

# delete elements
s.remove(2)
print(s)

# & |
s1 = {3, -2, 7}
s2 = {1, 9, -2}
print(s1 & s2)
print(s1 | s2)
