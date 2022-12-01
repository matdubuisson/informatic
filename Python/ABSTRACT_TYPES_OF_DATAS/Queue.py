class Queue:

  class Node:

    def __init__(self, next=None, data=None):
      self.next = next
      self.data = data

  def __init__(self):
    self.first = None
    self.length = 0

  def __len__(self):
    return self.length

  def __str__(self):
    s = "[ "
    node = self.first
    while node != None:
      s += "{0} ".format(node.data)
      node = node.next
    return s + "]"

  def enqueue(self, data=None):
    node = Queue.Node(self.first, data)
    self.first = node
    self.length += 1

  def dequeue(self):
    if self.length > 0:
      self.length -= 1
      node = self.first
      if node.next == None:
        self.first = None
        node.next = None
        return node.data
      while node.next.next != None:
        node = node.next
      old_node = node.next
      node.next = None
      return old_node.data
    return None

if __name__ == "__main__":
  s = Queue()
  print("==>", s)
  s.enqueue("word")
  print("==>", s)
  print("=>", s.dequeue())
  print("==>", s)
  for i in range(10):
    if i % 2 == 0:
      s.enqueue(i)
    else:
      s.enqueue(str(i) + "word")
  print("==>", s)
  result = 0
  while result != None:
    result = s.dequeue()
    print("=>", result)
  print("==>", s)
