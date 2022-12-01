#coding:utf-8

from threading import *
import time

def fct0():
  e = 0
  while e < 11:
    e += 1
    print("E = " + str(e))
    time.sleep(1)

def fct1():
  a = 0
  while a < 11:
    a += 1
    print("A = " + str(a))
    time.sleep(1)

th0 = Thread(target=fct0)
th1 = Thread(target=fct1)

th0.start()
th1.start()

th0.join()
th1.join()
