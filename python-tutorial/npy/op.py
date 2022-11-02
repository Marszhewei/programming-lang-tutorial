#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import numpy as np
from numpy import pi


def main():
    a = np.array((10, 20, 30, 40))
    b = np.arange(4)
    c = a - b
    print(c)
    print(b**2)
    print(10 * np.sin(a))
    print(a < 25)

    a = np.array([[1, 1], [0, 1]])
    b = np.array([[2, 0], [3, 4]])
    print(a * b)
    # matrix multi
    print(a @ b)
    print(a.dot(b))

    a = np.ones((2, 3), dtype=int)
    b = np.random.random((2, 3))
    a *= 3
    print(a)
    b += a
    print(b)
    # a += b float64 to int64(error)
    c = np.exp(b * 1j)
    print(c)
    print(c.dtype.name)

    # sum min max
    a = np.random.random((2, 3))
    print(a)
    print(a.sum())
    print(a.min())
    print(a.max())

    b = np.arange(12).reshape(3, 4)
    print(b)
    print(b.sum(axis=0))  # column
    print(b.min(axis=1))  # row
    print(b.cumsum(axis=1))

    # ufunc
    c = np.arange(3)
    print(c)
    print(np.exp(c))
    print(np.sqrt(c))
    d = np.array([2.0, -1.0, 4.0])
    print(np.add(c, d))

    # index slice iter
    a = np.arange(10) ** 3
    print(a)
    print(a[2])
    print(a[2:5])
    a[:6:2] = 1000
    print(a)
    print(a[::-1])
    for i in a:
        print(i ** (1 / 3.0))
    # in high-dimensional
    def f(x, y):
        return x * 10 + y

    a = np.fromfunction(f, (5, 4), dtype=int)
    print(a)
    print(a[2, 3])
    print(a[0:5, 1])
    print(a[:, 1])
    print(a[1:3, :])
    print(a[-1])  # a[-1, :] a[-1,...]

    c = np.array([[[0, 1, 2], [10, 12, 13]], [[100, 101, 102], [110, 112, 113]]])
    print(c.shape)
    print(c[..., 2])
    for row in c:
        print(row)
    for n in c.flat:
        print(n, end=' ')
    print()


if __name__ == "__main__":
    main()
