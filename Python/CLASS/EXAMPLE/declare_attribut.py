class Test:
  var = 0
  __var2 = 0
  def __init__(self):
    self.nbr = 14
    self.__nbr2 = 16
    Test.__var2 += 1

  def print_var2(self):
    print(Test.__var2)

  def get_nbr2(self):
    return self.__nbr2

  def set_nbr2(self, n=0):
    self.__nbr2 = n

instance = Test()

print(Test.var, instance.nbr) # This line doesn't return errors

try:
  print(Test.__var2)
except:
  print("You can't print the private attribut [ Test.__var2 ]")

try:
  print(instance.__nbr2)
except:
  print("You can't print the private attribut [ instance.__nbr2 ]")

# But there is an other manner to do it :
instance.print_var2()
print(instance.get_nbr2())

instance.set_nbr2(1308)
print(instance.get_nbr2())

new_instance = Test()

# Pay attention for the two line !!
new_instance.print_var2()
instance.print_var2()
