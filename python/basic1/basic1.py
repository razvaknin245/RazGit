def is_even(num):
    if(0 == num % 2):
        return True
    else : return False

def print_num(s,num = 1):
    i = 0
    while(i < num):
        print(s)
        i+=1

def check_leap(year):
    if year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
        print("LEAP")
    else:
        print("NOT LEAP")

def is_long(num):
    if(isinstance(num,long)):
        return True
    else:
        return False

def flip_num(num):
    reverse = 0
    curr = 0
    while(num != 0):
        curr = int(num) % 10
        reverse = reverse * 10
        reverse = reverse + curr
        num = int(num) // 10
        
    print("num is : " + str(reverse))
    #float = dont swap
    #string = break the code , need to fix with casting to int

def translate_grade(grade):
    if(grade >= 0 and grade <= 10):
        return 'F'
    elif(grade <= 30):
        return 'E'
    elif(grade <= 50):
        return 'D'
    elif(grade <= 70):
        return 'C'
    elif(grade <= 90):
        return 'B'
    else:
        return 'A'

def factorial(num):
    return True if(num == 1 or num == 0) else num * factorial(num - 1)