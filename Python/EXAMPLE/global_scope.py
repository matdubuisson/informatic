Global_var = 14

def get_Global_var():
  return Global_var

def set_Global_var(n):
  global Global_var
  Global_var = n

print(Global_var)
print(get_Global_var())
set_Global_var(16)
print(Global_var)
