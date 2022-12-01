from time import sleep

file = "00) Installation and Compilation Python.doc.txt"

with open(file, "r") as f:
  for each in f.read():
    print(each, end="", flush=True)
    sleep(0.05)
