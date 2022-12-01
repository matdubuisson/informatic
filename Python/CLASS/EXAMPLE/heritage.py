# There aren't pirvate elements as it doesn't work with the heritage !!
class Mother:
  nbr = 14
  @classmethod
  def get_number(cls):
    return cls.nbr
  def __init__(self, name):
    self.mother_name = name
  def __str__(self):
    return "Mother is {0}".format(self.mother_name)

class Daugther(Mother):
  def __init__(self, name, mother_name):
    super().__init__(mother_name)
    self.name = name
  def __str__(self):
    return "Daugther is {0}, it's a {1} and her ".format(self.name, self.get_sex()) + super().__str__()
  def get_sex(self):
    return "Female"

object = Daugther("Fille", "Mere")

print(object)
print(object.get_sex())
print(object.name, object.mother_name)
print(Daugther.nbr, Daugther.get_number())
