import os
import sqlite3 as sq

files = ("test.sql",)
searched_files = ("search.sql",)
encrypted_file = "result.sqlite"
if os.path.isfile(encrypted_file):
  os.remove(encrypted_file)

conn = sq.connect(encrypted_file)

cur = conn.cursor()

#########################################################

for each in files:
  try:
    with open(each, "r") as f:
      contain = f.read()
    contain = contain.strip().split(";")
    for each2 in contain:
      each2 = each2.strip() + ";"
      cur.execute(each2)
  except FileNotFoundError:
    print("Error : The file {0} isn't found !!".format(each))

for each in searched_files:
  try:
    with open(each, "r") as f:
      contain = f.read()
    contain = contain.strip().split(";")
    for each2 in contain:
      print("============================")
      each2 = each2.strip() + ";"
      for each3 in cur.execute(each2):
        print(each3)
  except FileNotFoundError:
    print("Error : The file {0} isn't found !!".format(each))


#########################################################

conn.commit()

conn.close()
