#coding:utf-8

from threading import *

from tkinter import *

W = Tk()
W.title("test")
W.geometry("600x600+100+100")

settings_description = ["a", "b", "c", "d", "e", "Yolo !!"]
settings_value = ["A", "B", "C", "D", "E", "Tous au combat !!"]

settings_widgets = []

POSITIONNER = 0 # Position all elements

def change_setting(*args):
  str = args[1].get()  # Get the value of the entry
  if str != "":
    settings_value[int(args[0])] = str # Change the value in the settings_value[]
    args[2].set(str) # Change the textvariable of the button

SPACE = 20
def create_setting(e):
  global POSITIONNER
  VAR0 = StringVar(); VAR1 = StringVar()
  VAR1.set(settings_value[e])

  LAB = Label(W, text=settings_description[e])
  ENT = Entry(W, textvariable=VAR0)
  BTN = Button(W, textvariable=VAR1, command=lambda: change_setting(e, VAR0, VAR1))
  # LAB
  # ENT|BTN
  # [space]
  settings_widgets.append([LAB, ENT, BTN])

LEN = len(settings_description)
e = 0; a = 0
while e < LEN:
  create_setting(e)
  e += 1

#######################################################

def placeSettings(*args):
  global settings_widgets
  w = W.winfo_width()
  h = W.winfo_height()

  xywh = [0, 0, int(w / 5), int(h / 20)]
  jump = int(h / 20)
  e = 0
  while e < len(settings_widgets):
    xywh[0] = 0
    settings_widgets[e][0].place(x=xywh[0], y=xywh[1], width=xywh[2], height=xywh[3])
    xywh[1] += jump
    settings_widgets[e][1].place(x=xywh[0], y=xywh[1], width=xywh[2], height=xywh[3])
    xywh[0] = xywh[2]
    settings_widgets[e][2].place(x=xywh[0], y=xywh[1], width=xywh[2], height=xywh[3])
    xywh[1] += jump

    e += 1

W.bind("<Configure>", placeSettings)

mainloop()

quit()
