# First in and first out
# TAD File (french)

class Fifo:

  class Node:

    def __init__(self, data=None, next=None):
      self.next = next
      self.data = data

  def __init__(self):
    self.head = None

  def __str__(self):
    n = self.head
    msg = "FIFO :\n"
    while n != None:
      msg += str(n.data) + "\n"
      n = n.next
    return msg

  def add(self, data):
    n = self.Node(data, self.head)
    self.head = n
  
  def pop(self):
    n = self.head
    if n.next == None:
      self.head = None
      n.next = None
      return n.data
    else:
      while n.next.next != None:
        n = n.next
      n.next = None
      return n.data

if __name__ == "__main__":
  f = Fifo()
  print(f)
  f.add("a")
  f.add("b")
  f.add("c")
  f.add("d")
  f.add("e")
  print(f)
  f.pop()
  print(f)
  f.pop()
  print(f)
