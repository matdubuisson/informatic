fileName = input("What is the file to read ? ")
try:
  if fileName == "testing.py":
    raise NameError("This name is reserved to the program !!")
  with open(fileName, "r") as f:
    print(f.read())
except FileNotFoundError:
  print("The file doesn't exist or it is in an other directory !!")
except:
  print("This except is activated because you have input testing.py !!")
finally:
  print("Finally I'm always executed !!")
