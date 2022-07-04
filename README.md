# QuatLib
Quaternion library

# Quaternion
$ q = a + bi + cj + dk $

## Addition

$ q_1 = a_1 + b_1i + c_1j + d_1k $

$ q_2 = a_2 + b_2i + c_2j + d_2k $

$ q_1 + q_2 = \left(a_1 + a_2\right) + \left(b_1 + b_2\right)i + \left(c_1 + c_2\right)j + \left(d_1 + d_2\right)k$

## Multiplication

### Multiplications of basis elements
* $ i1 = 1i = i $
* $ j1 = 1j = j $
* $ k1 = 1k = k $
* $ i^2 = j^2 = k^2 = -1 $
* $ ij = k, ji = -k $
* $ jk = i, kj = -i $
* $ ki = j, ik = -j $
* $ ikj = -1 $

### Multiplication of two quaternions
$ q_1 = a_1 + b_1i + c_1j + d_1k $

$ q_2 = a_2 + b_2i + c_2j + d_2k $

$ q_1 * q_2 = a_1\left( a_2 + b_2i + c_2j + d_2k \right) + b_1i\left( a_2 + b_2i + c_2j + d_2k \right) + c_1j\left( a_2 + b_2i + c_2j + d_2k \right) + d_1k\left( a_2 + b_2i + c_2j + d_2k \right)$

$ = a_1a_2 + a_1b_2i + a_1c_2j + a_1d_2k $

$ + b_1a_2i - b_1b_2 + b_1c_2k - b_1d_2j  + $

$ + c_1a_2j - c_1b_2k - c_1c_2 + c_1d_2i  + $

$ + d_1a_2k + d_1b_2j - d_1c_2i - d_1d_2 $

$ = \left( a_1a_2 -b_1b_2 - c_1c_2 - d_1d_2 \right) $

$ + \left( a_1b_2 + b_1a_2 + c_1d_2 - d_1c_2 \right)i $

$ + \left( a_1c_2 - b_1d_2 + c_1a_2 - d_1b_2 \right)j $

$ + \left( a_1d_2 + b_1c_2 - c_1b_2 + d_1a_2 \right)k $

# Reference

https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation

