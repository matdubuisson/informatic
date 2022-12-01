Global_var = 14

def giveALocalVariableWithSameNameThanAGlobalVariable():
  # global Global_var # If it does it, it's an error !! Pay attention to this thing !!
  # Warning a local variable inside a function cans have the same name then a globale
  # variable whereas the global variable isn't called by the prefix 'global'
  Global_var = -3738
  return Global_var

def getGlobalVar():
  return Global_var # The function without the term global can read a global variable

def setGlobalVar(n):
  global Global_var # This prefix permits to write the variable
  Global_var = n

print("Get Global_var from global", Global_var)
print("Get Global_var from local of getGlobalVar", Global_var)
setGlobalVar(int(input("Set a value to Global_var by local of setGlobalVar : ")))
print("Get Global_var from local of getGlobalVar", Global_var)
print("Get Global_var from global", Global_var)
print(giveALocalVariableWithSameNameThanAGlobalVariable())

