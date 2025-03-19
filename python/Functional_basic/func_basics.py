import functools
#ex1 - 3  sum function
def sum_for(nums):
    i = 0
    for x in nums:
        i += x
    return i

lisa = [1,2,3,4,5]
print(sum_for(lisa))

def sum_reduc(lis):
    return(functools.reduce(lambda a , b : a + b,lis))

lisb = [1,2,3,4,6]
print(sum_reduc(lisb))

def sum_sum(lis):
    return sum(lis)

lisc = [1,2,3,4,7]
print(sum_sum(lisc))

#ex2 - list comprehension
newlist = [x if x % 2 == 0 else "odd" for x in range(101)] 
print(newlist)

#ex3 - seven_boom 3 functions
def seven_boom(number):
    newlist = []
    for x in range(number + 1):
        if (x % 7 == 0 or '7' in str(x)):
            newlist.append(x)
    return newlist

print(seven_boom(17))

def seven_boom_compre(number):
    return [x for x in range(number+1) if '7' in str(x) or x % 7 == 0]

newlist = []
newlist = seven_boom_compre(28)
print(newlist)

def seven_boom_map(number):
    return list(filter(None,map(lambda x : x if '7' in str(x) or x % 7 == 0 else None,range(number+1))))

newlist = []
newlist = seven_boom_map(37)
print(newlist)

#ex4 - list_to_dict
def list_to_dict(ls):
    dict1 = {}
    for i,val in enumerate(ls):
        dict1[i] = val
        
    return dict1
        

l = ['a', 'b', 'c']
dict1 = list_to_dict(l)
print(dict1)

dict2 = {i: val for i, val in enumerate(l)}
print(dict2)

#ex5 - num args
def num_arg(*arg):
    return len(arg)

print(num_arg(1,2,3,4,5,"six","seven","eight"))

#ex6 -check arguments contain name
def named_arg(*args,**kw):
    
    if('name' in kw):
            print(kw['name'])
    else:
        print("name not passed")
                

named_arg(1,2,3,name="Hello")

#ex7 - make_adder function
def make_adder(number):
    def add_number(num):
        num += number
        return num
    return add_number

add_3 = make_adder(3)
print(add_3(-1))
print(add_3(6))
