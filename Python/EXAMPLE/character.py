#coding:utf-8

chain = "Yolo !! Hey ologramme Yolo command ça va ?"

startSequence = 14
stopSequence = 35

print(chain.index("olo", startSequence, stopSequence))
# Between the 14th character and the 35th there is a "olo" at the place 23 !!
print(len(chain)) # = 42

print(chain.replace("olo", "uku", 2))
# It replaces the two first "olo" by two "uku" and it doesn't touch the third !!
