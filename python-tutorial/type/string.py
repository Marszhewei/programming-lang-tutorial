#!/usr/bin/env python3
# -*- coding: utf-8 -*-


stra = "ABC"
strb = stra
stra = "XYZ"
print(stra, strb)

ia = ord('a')
b = chr(98)
print(ia, b)

# unicode and utf-8 (bytes)
bs = 'ABC'.encode('ascii')
print(bs)
s0 = b'ABC'.decode('ascii')
s1 = b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8')
print(s0)
print(s1)

# length
print(len('abcde')) # char
print(len('中文'.encode('utf-8'))) # bytes

# format
print('hello %s' % 'world')
print('a is %d, b is %.1f' % (10, 3.24))