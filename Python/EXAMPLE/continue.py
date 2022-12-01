#coding:utf-8

def playToTheGame():
  print("You have done one party !!")

start = 1
var = ""
while True:
  print("Do you want to get an appel ?")
  var = str(input("==> "))
  if var == "yes":
    print("Ok good, good lunch !!")
    break
  elif var == "no":
    print("You have to taste my appel !! Are you sure ?")
  elif var == "maybe":
    print("I'm sure that is a yes !!")
  else:
    print("I don't understand your answer. I repeat the question....")
    continue # This term permits to skip the following instructions of the loop

  print("You haven't passed on the continue !!") # So here this intruction
