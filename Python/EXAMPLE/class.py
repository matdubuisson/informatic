#coding:utf-8
class man:
  def __init__(self, name, age, job, comment):
    self.name = str(name)
    self.age = int(age)
    self.old = 0
    if age > 60:
      self.old = 1
    self.job = job
    self.note = str(comment)
  def description(self):
    print(self.name + " is " + str(self.age))
    print("The job is " + self.job)
    if self.old:
      print("Old people !!")

Joe = man("Joe", 17, "Chieur professionel", "TATAYOYO !!")

Jerry = man("Jerry", 65, "Surgeon", "Good guy !!")

Joe.description()
print("===========================")

Jerry.description()
print("===========================")

print("Note of Joe : " + Joe.note)
