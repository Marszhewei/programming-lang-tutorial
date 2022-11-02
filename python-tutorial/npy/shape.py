#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import numpy as np
from numpy import newaxis


def main():
    a = np.floor(10 * np.random.random((3, 4)))
    print(a)
    print(a.shape)
    b = a.ravel()
    print(b)
    print(b.shape)
    a = a.reshape((2, 6))
    print(a)
    print(a.T)
    print(a.shape)
    print(a.T.shape)
    print(a.reshape(3, -1)) # automatic derivation
    # use np.resize to change it's self
    a.resize((4, 3))
    print(a)

    # stack
    a = np.floor(10*np.random.random((2,2)))
    print(a)
    b = np.floor(10*np.random.random((2,2)))
    print(b)
    c = np.vstack((a, b))
    print(c)
    c = np.hstack((a, b))
    print(c)

    # column_stack (row_stack)
    print(np.column_stack((a, b)))
    # difference between hstack and column_stack
    a = np.array([4., 2.])
    b = np.array([3., 8.])
    print(np.column_stack((a, b)))
    print(np.hstack((a, b)))
    # 1D to 2D
    print(a[:, newaxis])
    print(np.column_stack((a[:, newaxis], b[:, newaxis])))
    print(np.hstack((a[:, newaxis], b[:, newaxis])))

    # r_ c_
    print(np.r_[1:3, 0, 4])
    print(np.c_[1:3, [0, 0], [4, 4]])

    # hsplit vsplit
    a = np.floor(10 * np.random.random((2,12)))
    print(a)
    print(np.hsplit(a, 3))


if __name__ == '__main__':
    main()