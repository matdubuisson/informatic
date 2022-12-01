for each in range(5):
  print(each)

print("====================")

[ print(each) for each in range(5) ] # Same thing

print("====================")

[ print(each) for each in range(5) if each != 3 ]

def changeValue(Each):
  Each += 1
  Each *= 4
  Each **= 3
  print(Each)
  return Each

l = list(range(10))
[ changeValue(each) for each in l if each != 3 ]
