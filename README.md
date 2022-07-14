# QuatLib
Quaternion library

# Quaternion
$$ q = a + bi + cj + dk $$

## Addition

$$ q_1 = a_1 + b_1i + c_1j + d_1k $$

$$ q_2 = a_2 + b_2i + c_2j + d_2k $$

$$ q_1 + q_2 = \left(a_1 + a_2\right) + \left(b_1 + b_2\right)i + \left(c_1 + c_2\right)j + \left(d_1 + d_2\right)k $$

## Multiplication

### Multiplications of basis elements
$$ i1 = 1i = i $$
$$ j1 = 1j = j $$
$$ k1 = 1k = k $$
$$ i^2 = j^2 = k^2 = -1 $$
$$ ij = k, ji = -k $$
$$ jk = i, kj = -i $$
$$ ki = j, ik = -j $$
$$ ikj = -1 $$

### Multiplication of two quaternions
$$ q_1 = a_1 + b_1i + c_1j + d_1k $$

$$ q_2 = a_2 + b_2i + c_2j + d_2k $$

$$ q_1 * q_2 = a_1\left( a_2 + b_2i + c_2j + d_2k \right) + b_1i\left( a_2 + b_2i + c_2j + d_2k \right) + c_1j\left( a_2 + b_2i + c_2j + d_2k \right) + d_1k\left( a_2 + b_2i + c_2j + d_2k \right)$$

$$ = a_1a_2 + a_1b_2i + a_1c_2j + a_1d_2k $$

$$ + b_1a_2i - b_1b_2 + b_1c_2k - b_1d_2j  + $$

$$ + c_1a_2j - c_1b_2k - c_1c_2 + c_1d_2i  + $$

$$ + d_1a_2k + d_1b_2j - d_1c_2i - d_1d_2 $$

$$ = \left( a_1a_2 -b_1b_2 - c_1c_2 - d_1d_2 \right) $$

$$ + \left( a_1b_2 + b_1a_2 + c_1d_2 - d_1c_2 \right)i $$

$$ + \left( a_1c_2 - b_1d_2 + c_1a_2 - d_1b_2 \right)j $$

$$ + \left( a_1d_2 + b_1c_2 - c_1b_2 + d_1a_2 \right)k $$


## Rotation

Euclidean vectors $\left(a_x, a_y, a_z\right)$ in $ R^3 $ can be rewritten as $a_xi+a_yj+a_zk $, where $i$, $j$ and $k$ are unit vectors representing the tree Cartesian axes.

A rotation of angle $\theta$ around the axis defined by the unit vector $ u = u_xi+u_yj+u_zk $ can be represented by a quaternion using an extension [2] of Euler's formula [3].

$$ e^{ix} = cos x + i sin x $$

$$ q = e^{\frac{\theta}{2}\left(u_xi+u_yj+u_zk\right)} = cos\frac{\theta}{2} + \left(u_x+u_yj+u_zk\right)sin\frac{\theta}{2} $$


The rotation can be applied to an ordinary vector $ p = \left(p_x, p_y, p_z\right) = p_xi+p_yj+p_zk $ in $R^3$ as $p' = qpq^*$, where

$$ q^* = e^{-\frac{\theta}{2}\left(u_xi+u_yj+u_zk\right)} = cos\frac{\theta}{2} - \left(u_xi+u_yj+u_zk\right)sin\frac{\theta}{2} $$

The result of $p' = qpq^*$ is as follows and its the result of Rotate() implemented in [quaternion_operations.h](quaternion_operations.h).

$$ p' = \left(q_{r} \left(a_{x} q_{r} - a_{y} q_{z} + a_{z} q_{y}\right) + q_{x} \left(a_{x} q_{x} + a_{y} q_{y} + a_{z} q_{z}\right) + q_{y} \left(- a_{x} q_{y} + a_{y} q_{x} + a_{z} q_{r}\right) - q_{z} \left(a_{x} q_{z} + a_{y} q_{r} - a_{z} q_{x}\right)\right) i + \\\\ \left(q_{r} \left(a_{x} q_{z} + a_{y} q_{r} - a_{z} q_{x}\right) - q_{x} \left(- a_{x} q_{y} + a_{y} q_{x} + a_{z} q_{r}\right) + q_{y} \left(a_{x} q_{x} + a_{y} q_{y} + a_{z} q_{z}\right) + q_{z} \left(a_{x} q_{r} - a_{y} q_{z} + a_{z} q_{y}\right)\right) j + \\\\ \left(q_{r} \left(- a_{x} q_{y} + a_{y} q_{x} + a_{z} q_{r}\right) + q_{x} \left(a_{x} q_{z} + a_{y} q_{r} - a_{z} q_{x}\right) - q_{y} \left(a_{x} q_{r} - a_{y} q_{z} + a_{z} q_{y}\right) + q_{z} \left(a_{x} q_{x} + a_{y} q_{y} + a_{z} q_{z}\right)\right) k $$

Note that the real part is zeroed out during the computation.

### Quaternion-derived rotation matrix
Rotation matrix for $q = q_r + q_xi + q_yj + q_zk$ is derived by using sympy in [quaternion.ipynb](quaternion.ipynb).

$$ R = \begin{bmatrix}qr^{2} + q_x^{2} - q_y^{2} - q_z^{2} & - 2 q_r q_z + 2 q_x q_y & 2 q_r q_y + 2 q_x q_z \\\\2 q_r q_z + 2 q_x q_y & q_r^{2} - q_x^{2} + q_y^{2} - q_z^{2} & - 2 q_r q_x + 2 q_y q_z \\\\- 2 q_r q_y + 2 q_x q_z & 2 q_r q_x + 2 q_y q_z & q_r^{2} - q_x^{2} - q_y^{2} + q_z^{2}\end{bmatrix} $$


If $q$ is pure rotation, $\lVert q\rVert = q_r^2 + q_x^2+q_y^2 + q_z^2 = 1$

Therefore the rotation matrix can be rewritten as 

$$R = \begin{bmatrix}1 - 2\left(q_y^{2} - q_z^{2}\right) & 2 \left( q_x q_y - q_r q_z\right) & 2\left( q_r q_y + q_x q_z\right) \\\\ 2\left( q_r q_z + q_x q_y\right) & 1 - 2\left(q_x^{2} - q_z^{2}\right) & 2\left(q_y q_z - q_r q_x\right) \\\\ 2\left( q_x q_z - q_r q_y\right) & 2\left( q_r q_x + q_y q_z \right) & 1 - 2\left( q_x^{2} - q_y^{2}\right) \end{bmatrix}$$

The matrix is the result of ToRotationMatrix() implemented in [quaternion_operations.h](quaternion_operations.h).




# Reference

[1] https://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation

[2] https://en.wikipedia.org/wiki/Pauli_matrices

[3] https://en.wikipedia.org/wiki/Euler%27s_formula

