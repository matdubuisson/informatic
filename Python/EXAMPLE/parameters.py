# Avoid function with one required parameter
def print_a_list(l):
  print(l)

# Avoid function with several required parameters
def print_grander_number(a, b, c):
  print("A =", a, "b =", b, "c =", c)
  if a > b:
    print(a)
    return
  if b > c:
    print(b)
    return
  print(c)

# Fruitful function with one required parameter
def get_increment(n):
  return n + 1

# Avoid function with a optional parameter
def print_a_number(n=14):
  print(n)

# Fruitful function with several optional parameters
def count(a=0, b=1, c=2):
  print("A =", a, "b =", b, "c =", c)
  return a + b + c

print_a_number(range(14))

var = 14
var = get_increment(var)
print(get_increment(var))

# get_increment() # => It'll return an error
# print_grander_number(a, c) # => It's ll return
# an error as there aren't quite enough parameters

for A in range(3):
  for B in range(3):
    for C in range(3):
      print_grander_number(A, B, C)

print_a_number() # It'll print 14
print_a_number(16)

print(count(15)) # It'll be : 15 + 1 + 2 = 18
