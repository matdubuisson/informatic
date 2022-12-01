def print_a_number():
  print(14)

def print_an_expression():
  n = 5
  h = 8
  print(n + h * n ** h)
  return
  # This dangerous code won't be never executed !!
  for i in range(100000000):
    print("Yolo !!")

def get_a_number():
  return 16

def get_an_expression():
  return 4 * 6 + 9 // 5

print_an_expression()
for e in range(4):
  print_a_number()
print_an_expression()

print(get_a_number())
var = get_a_number()
print(var)
print(get_an_expression())

print("==>", print_a_number())
