from tkinter import N


age = 3
if age >= 18:
    print('adult')
elif age >= 6:
    print('teenager')
else:
    print('kid')

# loop
names = ['jack', 'mars', 'jhon']
for name in names:
    print(name)

s = 0
for i in range(1, 11):
    s += i
print(s)
print(list(range(1, 11)))

s, n = (0, 10)
while n > 0:
    s += n
    n -= 1
print(s)