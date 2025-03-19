class X(object):
    def __init__(self,a):
        self.a = a
    
    def __getattr__(self, name):
        print("attribute named '{name}' does not exist ")

print(X(1).a)
X(1).b

class Y(object):
    def __init__(self, a):
        self.__dict__['a'] = a
    
    def __getattr__(self,name):
          print("attribute named '{name}' does not exist ")
          
    def __setattr__(self, name, value):
        if (name in self.__dict__ or name in self.__class__.__dict__):
            super().__setattr__(name, value)
        else:
            raise AttributeError("cannot add new attributes")

y = Y(3)
print(y.a)

class Z(object):
    __slots__ = ["a"]
    def __init__(self,a):
        self.a = a

    def __setattr__(self, name, value):
        if name in self.__slots__:
            super().__setattr__(name,value)
        else:
             raise AttributeError("cannot add new attributes")

z = Z(1)
print(z.a)   
z.b = 42
