class Test:
  msg = "Yolo !!"
  @classmethod
  def print_message_from_class(cls):
    print("From class :", cls.msg)

  def print_message_from_instance(self):
    print("From instance :", Test.msg)

Test.print_message_from_class()

instance = Test()
instance.print_message_from_instance()

try:
  Test.print_message_from_instance()
  instance.print_message_from_class()
except:
  print("It isn't allowed to do it !!")
