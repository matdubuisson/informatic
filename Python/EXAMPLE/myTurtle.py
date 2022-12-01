#coding:utf-8

from turtle import *

wn = Screen()

wn.bgcolor("black")

tt = Turtle()

tt.shape("turtle")
tt.color("white")

tt.forward(100)
tt.penup()
tt.forward(100)
tt.pendown()
tt.forward(100)

tt.speed(1)
tt.left(-90)
tt.color("blue")
tt.forward(100)

tt.speed(10)
tt.left(-90)
tt.color("yellow")
tt.forward(200)
tt.stamp()
tt.forward(300)

tt.shape("classic")
tt.speed(5)
tt.color("red")
tt.left(-120)
tt.forward(300)

tt.write("test")

tt.stamp()
tt.shape("turtle")
tt.speed(3)
tt.color("white") 
tt.left(-140)
tt.forward(200)
tt.stamp()
tt.forward(200)

tt.write("test")

wn.mainloop()
