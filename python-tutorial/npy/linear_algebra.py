#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import numpy as np


def main():
    a = np.array([[1., 2.], [3., 4.]])
    print(a)
    print(a.transpose())
    print(np.linalg.inv(a))
    u = np.eye(2)
    print(u)
    j = np.array([[0.0, -1.0], [1.0, 0.0]])
    print(j @ j)
    print(np.trace(u))
    y = np.array([[5.], [7.]])
    print(np.linalg.solve(a, y))
    print(np.linalg.eig(j))

if __name__ == '__main__':
    main()