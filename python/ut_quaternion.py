import unittest
import numpy as np
from quaternion import Quaternion

class QuaternionTest(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass


    def  test_add(self):
        q1 = Quaternion(np.array([0, 1, 2, 3]))
        q2 = Quaternion(np.array([1, 2, 3, 4]))

        q3 = q1 + q2
        print(q3)

        self.assertEqual(q3[0], 1)
        self.assertEqual(q3[1], 3)
        self.assertEqual(q3[2], 5)
        self.assertEqual(q3[3], 7)

    def  test_sub(self):
        q1 = Quaternion([1, 1, 2, 4])
        q2 = Quaternion([0, 3, 2, 3])
        
        q3 = q1 - q2
        print(q3)

        self.assertEqual(q3[0], 1)
        self.assertEqual(q3[1], -2)
        self.assertEqual(q3[2], 0)
        self.assertEqual(q3[3], 1)

    def test_mul(self):
        q1 = Quaternion([1, 2, 3, 4])
        q2 = Quaternion([3, 4, 5, 6])
        
        q3 = q1 * q2
        print(q3)

        a1 = 1.0
        b1 = 2.0
        c1 = 3.0
        d1 = 4.0

        a2 = 3.0
        b2 = 4.0
        c2 = 5.0
        d2 = 6.0

        a3 = (a1*a2) - (b1*b2) - (c1*c2) - (d1*d2);  # real
        b3 = (a1*b2) + (b1*a2) + (c1*d2) - (d1*c2);  # i
        c3 = (a1*c2) - (b1*d2) + (c1*a2) + (d1*b2);  # j
        d3 = (a1*d2) + (b1*c2) - (c1*b2) + (d1*a2);  # k
        self.assertEqual(q3[0], a3)
        self.assertEqual(q3[1], b3)
        self.assertEqual(q3[2], c3)
        self.assertEqual(q3[3], d3)

    def test_angle_to_quaternion(self):
        roll = 0.1
        pitch = 0.2
        yaw = 0.3

        qr = Quaternion()
        qr.to_quaternion(roll, pitch, yaw)
        roll2, pitch2, yaw2 = qr.to_euler_angles()

        self.assertAlmostEqual(roll, roll2)
        self.assertAlmostEqual(pitch, pitch2)
        self.assertAlmostEqual(yaw, yaw2)

    def test_angle_to_quaternion(self):

        p = Quaternion([0, 1, 0, 0])

        # rotate around k-axis by 45 deg
        qr = Quaternion()
        qr.to_quaternion(0, 0, np.pi/4)
        p2 = p.rotate(qr)

        ax, ay, az = qr.rotation_axis()
        angle = qr.rotation_angle()
        print("axis: {}, {}, {}".format(ax, ay, az))
        print("angle: {}".format(angle))
        print(p2)

        self.assertAlmostEqual(p2[1], np.sqrt(2)/2)
        self.assertAlmostEqual(p2[2], np.sqrt(2)/2)

    def test_angle_to_quaternion2(self):

        p = Quaternion([0, 1, 0, 0])

        # rotate around j-axis and k-axis by 45 deg
        qr = Quaternion()
        qr.to_quaternion(0, np.pi/4, np.pi/4)
        p2 = p.rotate(qr)

        # (1, 0, 0)
        
        # rotation around j-axis (y) - pitch
        #  sqrt(2)/2 0 sqrt(2)/2
        #  0         1 0
        # -sqrt(2)/2 0 sqrt(2)/2
        # = (sqrt(2)/2, 0, -sqrt(2)/2)

        # rotation around k-axis (z) - yaw
        # sqrt(2)/2 -sqrt(2)/2 0
        # sqrt(2)/2  sqrt(2)/2 0
        # 0          0         1
        # = (0.5, 0.5, -sqrt(2)/2)

        ax, ay, az = qr.rotation_axis()
        angle = qr.rotation_angle()
        print("axis: {}, {}, {}".format(ax, ay, az))
        print("angle: {}".format(angle))
        print(p2)

        self.assertAlmostEqual(p2[1], 0.5, 6)
        self.assertAlmostEqual(p2[2], 0.5, 6)
        self.assertAlmostEqual(p2[3], -np.sqrt(2)/2, 6)
    
    def test_set_axis_angle(self):

        # rotation around (1,1,0) by 180 deg.
        # y     (1, 1, 0)
        # |   /
        # | /
        # +--------- x
        qr = Quaternion()        
        qr.set_axis_angle(1, 1, 0, np.pi)

        # p = (1, 0, 0)
        p = Quaternion([0, 1, 0, 0])
        p2 = p.rotate(qr)

        # rotation of (1, 0, 0) around (1,1,0) by 180 deg = (0, 1, 0)
        self.assertAlmostEqual(p2[0], 0.0, 6)
        self.assertAlmostEqual(p2[1], 0.0, 6)
        self.assertAlmostEqual(p2[2], 1.0, 6)
        self.assertAlmostEqual(p2[3], 0.0, 6)


        qr = Quaternion()        
        qr.set_axis_angle(1, 1, 0, np.pi/2)

        # p = (1, 0, 0)
        p = Quaternion([0, 1, 0, 0])
        p2 = p.rotate(qr)
        print(p2)

        # # rotation of (1, 0, 0) around (1,1,0) by 90 deg = (0, 1, 0)
        self.assertAlmostEqual(p2[0], 0.0, 6)
        self.assertAlmostEqual(p2[1], 0.5, 6)
        self.assertAlmostEqual(p2[2], 0.5, 6)
        self.assertAlmostEqual(p2[3], -1/np.sqrt(2), 6)


if __name__ == '__main__':
    unittest.main()

    