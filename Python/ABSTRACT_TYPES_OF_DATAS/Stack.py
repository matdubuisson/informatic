class Stack:

  class Node:

    def __init__(self, next=None, data=None):
      self.next = next
      self.data = data

  def __init__(self):
    self.length = 0
    self.first = None

  def __str__(self):
    s = "[ "
    node = self.first
    while node != None:
      s += "{0} ".format(node.data)
      node = node.next
    return s + "]"

  def __len__(self):
    return self.length

  def push(self, data=None):
    node = Stack.Node(self.first, data)
    self.first = node
    self.length += 1

  def pop(self):
    if self.length > 0:
      node = self.first
      self.first = node.next
      node.next = None
      self.length -= 1
      return node.data
    return None

if __name__ == "__main__":
  s = Stack()
  print("==>", s)
  s.push("word")
  print("==>", s)
  print("=>", s.pop())
  print("==>", s)
  for i in range(10):
    if i % 2 == 0:
      s.push(i)
    else:
      s.push(str(i) + "word")
  print("==>", s)
  result = 0
  while result != None:
    result = s.pop()
    print("=>", result)
  print("==>", s)
