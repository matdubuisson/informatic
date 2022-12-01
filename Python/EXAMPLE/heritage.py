#coding:utf-8

class team():
  def __init__(self, color):
    self.team = str(color)

class player(team):
  def __init__(self, name="Anonymous", specy="Human", color="White"):
    self.name = str(name)
    self.specy = str(specy)
    team.__init__(self, color)
  def show_description(self):
    print(self.name + " is a " + self.specy + " in the " + self.team + " team !!")

joe = player("Joe", "PNJ", "Red")
randomMan = player()

joe.show_description()
randomMan.show_description()

if isinstance(joe, player):
  print("The variable [ joe ] is a class from [ player ] !!")

if isinstance(joe, team):
  print("The variable [ joe ] is a class from [ team ] !!")

if issubclass(player, team):
  print("The class [ player ] is contained in the class [ team ] !!")

if issubclass(player, team):
  print("The class [ team ] is contained in the class [ player ] !!")
else:
  print("The class [ team ] isn't contained in the class [ player ] !!")
