#coding:utf-8

var = ""
while True:
  print("Am I the best ?", end=" ")
  var = str(input())

  if var == "yes":
    break # The break is only used for a loop !!
  elif var == "no":
    print("It isn't good to say a lying !!")
  elif var == "maybe":
    print("Only the truth is true...")
  else:
    print("You say a strange sentence !!")
  print("")

print("Cool I'm glad that you say the truth !!")
