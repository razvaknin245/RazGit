import math 
import numbers

class Point(object):
    def __init__(self,x = 0.0,y = 0.0):
        #ex1 without nubmers
        if not isinstance(x,(int,float) or not isinstance(y , (int,float))):
            print("Error x and y must be nubmer")
            self.x = 0.0
            self.y = 0.0

        #ex2 with numbers
        elif not isinstance(x,numbers.Number) or not isinstance(y , numbers.Number):
            print("Error x and y must be nubmer")
            self.x = 0.0
            self.y = 0.0

        else:   
            self.x = x
            self.y = y
    def distance_from_origin(self):
        #ex1 without math : return ((self.x **2) + (self.y ** 2)) ** 0.5
        #ex3 with math 
        return math.sqrt(self.x **2 + self.y **2)

p = Point(1 , 1)
print("x is",p.x,"y is",p.y)
print("distance from origin is ",p.distance_from_origin())