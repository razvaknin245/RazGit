#ex1
import os
def filename(filepath):
    return os.path.basename(filepath)



#ex2
def turn_cap(filepath):
    fo = open(filepath,"r")
    y = fo.read().upper()
    capfo = open(filepath,"w")
    capfo.write(y)
    capfo.close()
    fo.close()
    
turn_cap("/home/raz/Downloads/filepy.txt")

#ex3
def is_prime(n):
    for i in range(2,n):
        if(n % i) == 0:
            return False
    return True

print(is_prime(2))
print(is_prime(73))
print(is_prime(74))
print(is_prime(83))
print(is_prime(1103))

#ex4
x = lambda a : a**2
print(x(5))

#ex5
add = lambda a , b: a + b
add(5,15)

#ex6
def reducelist(string):
    no_dunder = []
    for method_name in dir(string):
        if not method_name.startswith("__"):
            no_dunder.append(method_name)
    print(no_dunder)
def reducedunder(string):
    no_dunder = [method_name for method_name in dir(string)if not method_name.startswith("__")]
    print(no_dunder)
reducelist("example string")
reducedunder("example string")



#ex7
inc = lambda lis : [num + 1 for num in lis]
print(inc([1,2,3]))

#ex8
def remove_nonstr(lis):
       return [item for item in lis if isinstance(item,str)]
    
lis = ["raz",1,[2,4],False,True,5,6,"vaknin"]
print(lis)
lis = remove_nonstr(lis)
print(lis)

#ex9
def enu_list(st):
    for item in enumerate(st):
        print(item)
mylist = ["raz", "vaknin", "other"]
enu_list(mylist)

#ex10
def dict_list_enu(dicto):
    for (key, val) in dicto.items():
        print(f"{key}: {val}")

Dicto = {"Raz": 1, "vaknin": 2, "another_raz": 3, "another_vaknin": 4}
dict_list_enu(Dicto)


#ex11
def list_to_dict(lis):
    res = {}
    for i in range(len(lis)):
        res[i] = lis[i]
    return res

list_to_dict_b = lambda lis : { i : lis[i] for i in range(len(lis))}
                               
print(list_to_dict(["raz", "vaknin", "other"]))
print(list_to_dict_b(["raz", "vaknin", "other"]))                               

#ex12
class DefaultDict(dict):
    def __init__(self, default_value):
        self.default_value = default_value
        super().__init__()

    def __missing__(self, value):
        return self.default_value

d = DefaultDict(0)
d['a'] = "hello"
print(d['a'])
print(d['b'])


#ex13
def squared_numbers():
    num = 0
    while True:
        yield num ** 2
        num += 1
squares_generator = squared_numbers()

for i in range(10):
    print(next(squares_generator))
        

#ex14
class Node:
    def __init__(self,data,next = None):
        self._data = data
        self._next = next
    @property
    def data(self):
        return self._data

    @data.setter
    def data(self, value):
        self._data = value

    @property
    def next(self):
        return self._next

    @next.setter
    def next(self, value):
        self._next = value

class LinkedList:
    def __init__(self,*args):
        self._head = None
        self._len = 0
        for i in args:
            self.push_begin(i)
   
    def __iter__(self):
        node = self._head
        while node is not None:
            yield node._data
            node = node._next
            
    def __len__(self):
        return self._len
    
    def __repr__(self):
        return f"LinkedList({', '.join(repr(data) for data in self)})"
    
    def __str__(self):
        return "->".join(str(data) for data in self)
        
    def __bool__(self):
        return bool(self._head)
    
    def push_begin(self, data):
        new_node = Node(data, self._head)
        self._head = new_node
        self._len += 1
        
    def pop_begin(self):
        if self._head is None:
            raise ValueError("pop from an empty list")
        data = self._head.data
        self._head = self._head.next
        self._len -= 1
        return data

    def remove(self,data):
        if self._head is None:
            raise ValueError("The List Is Empty")
        if self._head.data == data:
            self._head = self._head.next
            self._size -= 1
            return
        prev = self._head
        node = self._head.next
        while node:
            if node.data == data:
                prev.next = node.next
                self._len -= 1
                return
            prev = node
            node = node.next
        raise ValueError(f"{data} is not in list")

sll = LinkedList(1,"hello",(5,6))
sll.remove("hello")
sll.push_begin("raz")
print(bool(sll))
print("len is " + str(len(sll)))
print(sll)
sll.pop_begin()
print("len is " + str(len(sll)))
print(sll)
sll.pop_begin()
print("len is " + str(len(sll)))
print(sll)
sll.pop_begin()
print("len is " + str(len(sll)))
print(bool(sll))

