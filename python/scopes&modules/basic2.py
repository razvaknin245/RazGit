def squaerd_num():
    i = 0
    squre = 0
    my_list = []
    while(i <= 10):
        squre = i ** 2
        my_list.append(squre)
        i += 1
    print(my_list)
    
def squaerd_num2():
    i = 0
    squre = 0
    my_list = []
    for i in range(11):
        squre = i ** 2
        my_list.append(squre)
    print(my_list)
squaerd_num()
squaerd_num2()

def all_even_wh():
    i = 0
    even_list = []
    while(i <= 100):
        even_list.append(i)
        i += 2
    print(even_list)
    
def all_even_f():
    even_list = []
    for i in range(0,101,2):
        even_list.append(i)
    print(even_list)
    
def all_even_range():
    even_list = []
    even_list = list(range(0,101,2))
    print(even_list)
    

def str_to_dict(st):
    dict = {letter : st.count(letter) for letter in set(st)}
    return dict


def enu_list(st):
    for item in enumerate(st):
        print(item)



def dict_list_enu(dict):
    for index,(key, val) in enumerate(dict.items()):
        print(f"Index {index}: {key}: {val}")


def check_lists(ls1,ls2):
    result = []
    for element in ls1:
        if element in ls2:
            result.append(element)
    return result
ls1 = ["raz","vaknin"]
ls2 = ["Raz","vaknin"]


def check_lists_way_two(ls1,ls2):
    set1 = set(ls1)
    set2 = set(ls2)
    return list(set1.intersection(set2))
ls1 = ["raz","vaknin","like"]
ls2 = ["Raz","vaknin","like"]

def check_lists_way_three(ls1,ls2):
    return (item in ls2 for item in ls2)
ls1 = ["three","way","check"]
ls2 = ["three","WAY","check"]

def rotate_left(ls,k):
    ls = ls[k:] + ls[:k]
    print(""+str(ls))

if __name__ == "__main__":
    all_even_f()
    all_even_range()
    all_even_wh()

    Dicto = str_to_dict("Hello")
    print(Dicto)

    mylist = ["raz", "vaknin", "other"]
    enu_list(mylist)

    Dicto = {"Raz": 1, "vaknin": 2, "another_raz": 3,   "another_vaknin": 4}
    dict_list_enu(Dicto)

    ls1 = ["raz","vaknin"]
    ls2 = ["Raz","vaknin"]
    res = check_lists(ls1,ls2)
    print(res)

    ls1 = ["raz","vaknin","like"]
    ls2 = ["Raz","vaknin","like"]
    res = check_lists_way_two(ls1,ls2)
    print(res)

    res = check_lists_way_two(ls1,ls2)
    print(res)

    test_list = [1,4,6,7,2]
    rotate_left(test_list,1)
