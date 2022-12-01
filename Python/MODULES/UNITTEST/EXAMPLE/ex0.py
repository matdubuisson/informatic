import unittest

def my_max(l):
  """
  @pre: l is a list of integer numbers
  @post: return the highest integer number of the list
  """
  m = None
  for each in l:
    if m == None:
      m = each
    else:
      if each > m:
        m = each
  return m

class TestMyMax(unittest.TestCase):
  def setUp(self):
    self.l = [ 7, 8, 0, 1, 9 ] # 9
    self.l2 = [ 5, 16, 11, 14, -4 ] # 16
    self.l3 = [ 0, -1, -14 ] # 0
    self.l4 = [] # None

  def test_my_max(self):
    self.assertEqual(my_max(self.l), 9)
    self.assertEqual(my_max(self.l2), 16)
    self.assertEqual(my_max(self.l3), 0)
    self.assertEqual(my_max(self.l4), None)

if __name__ == "__main__":
  unittest.main(verbosity=2)
