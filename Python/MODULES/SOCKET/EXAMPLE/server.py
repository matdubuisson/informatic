#coding:utf-8

from socket import *

MY_SOCKET = socket(AF_INET, SOCK_STREAM)

ADDR = str(input("IP : "))
PORT = int(input("PORT : "))

MY_SOCKET.bind((ADDR, PORT))

MY_SOCKET.listen(1)

clientSocket, clientAddress = MY_SOCKET.accept()

WORK = 1
while WORK:
  try:
    MSG = clientSocket.recv(1024).decode("utf-8")
    print(MSG)
    if MSG == 'exit':
      WORK = 0
  except:
    print("Connection stopped")
    WORK = 0

