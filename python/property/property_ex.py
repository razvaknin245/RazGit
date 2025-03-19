import numbers
class Point(object):
    """
    A Point class with two coordinates , x and y
    """
    def __init__(self):
        self.__x = 0.0
        self.__y = 0.0
        
    def get_x(self):
        """
        Return the x of point
        """
        return self.__x 
    def get_y(self):
        """
        Return the y of point
        """
        return self.__y
    
    def set_x(self,a):
        """
        set the x - coordinate of point
        only accept number
        """
        if not isinstance(a,numbers.Number):
            raise ValueError("Error coordinates must be nubmer")
            self.__x = 0.0
        else:
            self.__x = a
    def set_y(self,a):
        """
        set the y - coordinate of point
        only accept number
        """
        if not isinstance(a,numbers.Number):
            raise ValueError("Error coordinates must be nubmer")
            self.__y = 0.0
        else:
            self.__y = a
            
    x = property(get_x,set_x)
    y = property(get_y,set_y)
#x = Point()
#x.x = 5.5
#x.y = 2.5
#print(x.x)
#print(x.y)

help(Point)

help(Point)
