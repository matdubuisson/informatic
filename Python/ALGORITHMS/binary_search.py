# POTENTIELLE QUESTION D'EXAMEN

def binary_search(l, e):
  found = False
  first = 0
  last = len(l) - 1
  while first <= last and not found:
    middle = (first + last) // 2
    if l[middle] == e:
      return True
    elif l[middle] > e:
      last = middle - 1
    else:
      first = middle + 1
  return False

l = list(range(0, 33, 3))
print(l)
assert not binary_search(l, 17), "17 isn't present in the list"
assert binary_search(l, 21), "21 is present in the list"
