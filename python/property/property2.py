class Property:

    def __init__(self,fget = None,fset = None,fdel = None):
        self.fget = fget
        self.fset = fset
        self.fdel = fdel
        
    def __get__(self,instance, owner = None):
        if instance is None:
            return self
        if self.fget is None:
            raise AttributeError("cant read attribute")
        return self.fget(instance)
                                 
    def __set__(self,instance,value):
        if self.fset is None:
            raise AttributeError("cant set attribute")
        self.fset(instance,value)
    def __delete__(self,instance):
        if self.fdel is None:
            raise AttributeError("cant delete attribute")
        self.fdel(instance)
    
    def Setter(self,fset):
        return type(self)(self.fget,fset,self.fdel)
    def Deleter(self,fdel):
        return type(self)(self.fget,self.fset,fdel)

class X(object):
    def __setx(self,val):
        self.__x =val 
    def __init__(self,val):
        self.__setx(val)
    @Property
    def x(self):
        return self.__x
    @x.Setter
    def x(self,val):
        self.__x = int(val)
    @x.Deleter
    def x(self):
        del self.__x

a = X(0)
print(a.x)
a.x = 1
print(a.x)
del a.x