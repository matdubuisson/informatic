class BankAccount:
  __id = 0
  def __init__(self, name="Anonymous", money=0, code="00000000"):
    self.name = name
    self.__money = money
    self.__code = code
    self.__id = BankAccount.__id
    BankAccount.__id += 1

  def __get_code(self):
    return self.__code

  def add_money(self, count=0):
    self.__money += count

  def take_money(self, count=0, code=None):
    if code != None:
      if code == self.__get_code() and self.__money >= count:
        self.__money -= count
        return count
    return "Bad password !!"

  def print_money(self, code=None):
    if code == self.__get_code():
      print(self.__money)
    else:
      print("The code is wrong for {0}...".format(self.name))

linux = BankAccount("Linux", 140000, "Nunux")

windows = BankAccount("Windows", 1000000, "Microsoft")

try:
  linux.__get_code()
except:
  print("You cansn't tap into the code of linux !!")

linux.print_money("Nunux")
linux.add_money(123634)
linux.print_money("Nunux")

windows.print_money("?!")

print(linux.take_money(30000, "Nunux"))
print(linux.take_money(30000, "abcdefg"))
