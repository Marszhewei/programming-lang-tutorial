#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import numpy as np


def main():
    a = np.arange(12)
    b = a
    print(b is a)
    b.shape = (3, 4)
    print(a.shape)

    # view, share the memary
    c = a.view()
    print(c is a)
    print(c.base is a)
    c.shape = (2, 6)
    print(a.shape)
    c[0, 4] = 1234
    print(a)
    s = a[:, 1:3]
    s[:] = 10
    print(a)

    # copy
    d = a.copy()
    print(d is a)
    print(d.base is a)
    d[0, 0] = 999
    print(a)
    del a
    print(d)

    # index
    a = np.arange(12) ** 2
    i = np.array([1, 1, 3, 7])
    print(a[i])

    palette = np.array(
        [
            [0, 0, 0],
            [255, 0, 0],
            [0, 255, 0],
            [0, 0, 255],
            [255, 255, 255],
        ]
    )
    image = np.array(
        [[0, 1, 2, 0], [0, 3, 4, 0]]
    )
    print(palette[image])

    a = np.arange(12).reshape(3,4)
    print(a)
    i = np.array([[0, 1], [1, 2]])
    j = np.array([[2, 1], [3, 3]])
    print(a[i, j])
    print(a[i, 2])
    print(a[:, j])

    # ix_
    a = np.array([2, 3, 4, 5])
    b = np.array([8, 5, 4])
    c = np.array([5, 4, 6, 8, 3])
    ax, bx, cx = np.ix_(a, b, c)
    print(ax)
    print(bx)
    print(cx)
    print(ax.shape, bx.shape, cx.shape)
    res = ax + bx * cx
    print(res)
    print(res[3, 2, 4])
    print(a[3] + b[2] * c[4])
    


if __name__ == "__main__":
    main()
