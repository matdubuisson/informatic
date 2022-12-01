#coding:utf-8

from tkinter import *

WIN = Tk()

WIN.title("Console of racteurserver !!")
WIN.minsize(400, 400); WIN.maxsize(800, 800)
WIN.geometry("400x400+100+100"); WIN.resizable(width=1, height=1)

#################################################################

principalFrame = Frame(WIN, width=200, height=200, borderwidth=5)

principalFrame.pack()

#################################################################

print("DISPLAY : WIDTH = " + str(WIN.winfo_screenwidth()) + " AND HEIGHT = " + str(WIN.winfo_screenheight()))

mainloop()

quit()
