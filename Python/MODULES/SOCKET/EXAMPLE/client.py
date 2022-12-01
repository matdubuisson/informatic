#coding:utf-8

from socket import *

SOCKET_OF_SERVER = socket(AF_INET, SOCK_STREAM)

ADDR = str(input("IP : "))
PORT = int(input("PORT : "))

SOCKET_OF_SERVER.connect((ADDR, PORT))

WORK = 1
while WORK:
  MSG = str(input("MSG : "))
  if MSG == 'exit':
    WORK = 0
  try:
    SOCKET_OF_SERVER.send(MSG.encode("utf-8"))
  except:
    print("Connection stopped")
    WORK = 0
