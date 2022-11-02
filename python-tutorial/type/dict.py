scores = {'jack': 100, 'zwei': 87, 'mars': 60}
print(scores)

for key, val in scores.items():
    print(key, val)

# set or add key: val
scores['fetch150zy'] = 100
print(scores['fetch150zy'])

# replace val
scores['fetch150zy'] = 95
print(scores)

# avoid key is not exist
if 'fetch150zy' in scores:
    print(scores['fetch150zy'])
if 'mmzf' in scores:
    print(scores['mmzf'])
if None != scores.get('jack'):
    print(scores['jack'])
# you can set your own return value
if -1 == scores.get('mmzf', -1):
    print('Not found mmzf.')

# delete key
print(scores)
scores.pop('fetch150zy')
print(scores)

# tuple as key, but list can not
t = (1, 2, 3)
l = [1, 2, 3]
dt = {}
dt[t] = 'number'
dl = {}
# dl[l] = 'number' not allowed, because the list is changeable
print(dt)
print(dl)

# the same key?
d = {1: 'one', -2: 'two'}
d[1] = 'first'
print(d)
