import random as rd

object = rd.Random()
rnd_list = object.randrange(1, 10, 2) # It takes a random number in a
# list from 1 to 10 but the 2 does as range() for 1 + 2 = 3, 3 + 2 = 5
# 5 + 2 = 7, 7 + 2 = 9. In fact, it takes a random odd number between
# 1 and 10
print(rnd_list)
