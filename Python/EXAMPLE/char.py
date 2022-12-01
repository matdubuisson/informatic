#coding:utf-8

#chain = "abcdefghijklmnopqrstuvwxyz"
#for eachChar in chain:
#  print(eachChar)

index = -1
def getCommand(msg, cmd):
  global index
  chain = str(cmd)+" "
  index = msg.find(chain, 1, len(chain) + 1)
  if index != -1:
    return 1
  return 0

msg = str(input("=> "))

print(getCommand(msg, "echo"))
