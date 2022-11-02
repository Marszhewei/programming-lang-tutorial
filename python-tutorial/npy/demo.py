#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import numpy as np
from numpy import pi


arr = np.arange(15).reshape(3, 5)
print(arr)
print(arr.shape)
print(arr.ndim)
print(arr.dtype.name)
print(arr.dtype.itemsize)
print(arr.size)
print(type(arr))

b = np.array([1, 2, 3])
print(b.ndim)
print(type(b))


def main():
    # create array in numpy
    # use np.array to create array from a list or tuple
    a = np.array((3.1, 3.2, 3.3, 3.4)).reshape(2, 2)
    print(a)
    print(a.dtype)
    # can set dtype
    b = np.array([(1, 2), (3, 4)], dtype=complex)
    print(b)

    # zero matrix
    z = np.zeros((3, 4))
    print(z)

    # ones matrix
    o = np.ones((4, 4))
    print(o)

    # uninit matrix
    e = np.empty((2, 3))
    print(e)

    # use range(return array not list)
    a = np.arange(10.0, 20.0, 0.5).reshape(4, 5)
    print(type(a))
    print(a)

    # linspace
    l = np.linspace(0, 2, 9).reshape(3, 3)
    print(l)
    x = np.linspace(0, 2 * pi, 100).reshape(20, 5)
    print(x)

    # high-dimensional
    x = np.arange(24).reshape(2, 3, 4)
    print(x)

    # np.set_printoptions(threshold=sys.maxsize)   output all elements
    print(np.arange(100000))


if __name__ == '__main__':
    main()