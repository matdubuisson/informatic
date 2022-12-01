#coding:utf-8

class human:
  def __init__(self, nbr):
    self.value = int(nbr)
  def getter(self):
    return self.value
  def setter(self, newNbr):
    self.value = int(newNbr)
  def deleter(self):
    del self.value
  def informer(self):
    print("This program is useless with the only data : " + str(self.value))

Joe = human(14)
print(Joe.getter())
Joe.setter(16)
print(Joe.getter())
Joe.informer()
Joe.deleter()
try:
  print(Joe.getter())
except:
  print("The value of Joe is deleted !!")

print("\n====================================\n")

class human2:
  def __init__(self, nbr):
    self.value = int(nbr)
  def getter(self):
    return self._value
  def setter(self, newNbr):
    self._value = int(newNbr)
  def deleter(self):
    del self._value
  def informer(self):
    print("This program is useless with the only data : " + str(self._value))
  value = property(getter, setter, deleter, informer)

Joe2 = human2(14)
print(Joe2.getter())
Joe2.setter(16)
print(Joe2.getter())
Joe2.informer()
Joe2.deleter()
try:
  print(Joe2.getter())
except:
  print("The value of Joe2 is deleted !!")

