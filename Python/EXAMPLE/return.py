#coding:utf-8

def giveFirstOddNumber():
  for nbr in [14, 16, 58, 17, 39, 88]:
    if nbr % 2 != 0:
      return nbr

result = giveFirstOddNumber()
print("The first odd number is", result)
