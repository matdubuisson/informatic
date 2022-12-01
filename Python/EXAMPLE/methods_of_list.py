#coding:utf-8

l = "Salut comment ça va ?"
print(l)
l = l.split()
print(l)
l.extend(["Ça", "fait", "longtemps", "!!"])
print(l)
l = "_".join(l)
print(l)
l = l.split("_")
print(l)
l.remove(l[2])
print(l)
l.insert(1, "Mike")
print(l)
l[3] = "vas"
print(l)
l.insert(4, "tu")
print(l)
l.append("END")
print(l)
l.clear()
print(l)
