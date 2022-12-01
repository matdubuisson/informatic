#coding:utf-8

f = open("doc.txt", "r")
contain = f.read()
f.close()

"""
SAME THAN :
contain = 0
with open("doc.txt", "r") as f:
  contain = f.read()
"""

print(contain)

f2 = open("copy_of_doc.txt", "w")
f2.write(contain)
f2.close()

message = """
Hello I want to add this part of text in copy_of_doc.txt
thanks to the option of writing "a".
"""

f3 = open("copy_of_doc.txt", "a")
f3.write(message)
f3.close()

print("\n================\nCONTAIN OF copy_of_doc.txt :")
with open("copy_of_doc.txt", "r") as f4:
  print(f4.read())
