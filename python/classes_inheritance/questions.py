#question8
class X(object):
    def __init__(self,a):
        self.a = a
    #question9
    def foo(self,b):
        self.b = b

x = X(1)
x.z = 42
x.foo("hello")
print(x.a,x.b)

class B(object):
    def foo(self):
        return "B"

class D(B):
    def foo(self):
        return "D"

b = B()
d = D()
print (b.foo())
print (d.foo())