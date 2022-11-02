stu_name = ('jack', 'mars', 'zwei')
print(stu_name)
print(len(stu_name))

# you can't change elements
# stu_name[1] = 'jhon'
# print(stu_name)

# empty tuple and one element tuple
empty_tuple = ()
print(empty_tuple)
print(len(empty_tuple))
one_tuple = (1)
print(one_tuple)
# print(len(one_tuple)) can't get length of one element tuple

# changeable tuple?
cab = ('a', 'b', ['A', 'B'])
cab[-1][0] = 'X'
cab[-1][-1] = 'Y'
print(cab)

