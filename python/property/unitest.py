import unittest
import numbers
from property_ex import Point

class TestPoint(unittest.TestCase):
    def setUp(self):
        super().setUp()
        self.p = Point()

    def test_get_x(self):
        self.assertEqual(self.p.x, 0.0)

    def test_get_y(self):
        self.assertEqual(self.p.y, 0.0)

    def test_set_x(self):
        self.p.x = 5.0
        self.assertEqual(self.p.x, 5.0)

    def test_set_y(self):
        self.p.y = 5.0
        self.assertEqual(self.p.y, 5.0)

    def test_nonnumber_x(self):
        with self.assertRaises(ValueError):
            self.p.x = "not a number"

    def test_nonnumber_y(self):
        with self.assertRaises(ValueError):
            self.p.y = "not a number"


if __name__ == '__main__':
    unittest.main()

