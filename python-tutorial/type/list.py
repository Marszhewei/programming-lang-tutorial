stu_name = ['jack', 'mars', 'fetch150zy']
# get list length
print(len(stu_name))
# index
print(stu_name[0])
print(stu_name[1])
print(stu_name[len(stu_name) - 1])
print(stu_name[-1])
print(stu_name[-2])
# add elements
stu_name.append('jhon')
print(stu_name)
# insert elements
stu_name.insert(1, 'insert')
print(stu_name)
# pop elements
stu_name.pop()
print(stu_name)
stu_name.pop(1)
print(stu_name)
# replace elements
stu_name[1] = 'zwei'
print(stu_name)

# different type in list
multi_type = ['java', 123, True]
print(multi_type)
multi_type = ['java', ['c', 'cpp', 'c#'], 'python']
print(len(multi_type))
print(multi_type)

# empty list
ls = []
print(len(ls))


# list and string
l = [3, 1, 2]
l.sort()
print(l)
s = 'abc'
s.replace('a', 'A')
s1 = s.replace('a', 'A')
print(s)
print(s1)