
import hashlib
from string import ascii_lowercase as az
from string import digits as digt
from string import ascii_uppercase as AZ

import datetime as dat
import itertools

def shabrute(stri,numofchars,hash):
    start = dat.datetime.now()
    for guess in itertools.product(az,repeat = numofchars):
          trystr=''.join(guess)
          #print(trystr)
          if (hash(trystr.encode('utf-8')).hexdigest() == stri):
                end = dat.datetime.now()
                print("found " + ''.join(guess))
                print(end - start)
                return            

def digitsbrute(digits,numofdigits,hashfunc):
    start = dat.datetime.now()
    for guess in itertools.product(digt,repeat = numofdigits):
        trystr=''.join(guess)
        print(trystr)
        if (hashfunc(trystr.encode('utf-8')).hexdigest() == digits):
            end = dat.datetime.now()
            print("found " + ''.join(guess))
            print(end - start)
            return
def alphanumbrute(str,length,hashfunc):
    start = dat.datetime.now()
    keyspace = az+AZ+digt
    for guess in itertools.product(keyspace,repeat = length):
        trystr=''.join(guess)
        print(trystr)
        if (hashfunc(trystr.encode('utf-8')).hexdigest() == str):
            end = dat.datetime.now()
            print("found " + ''.join(guess))
            print(end-start)
            return
def main():
    hashstr = hashlib.sha256("razva".encode('utf-8')).hexdigest()
    hashsha1 = hashlib.sha1("shaha".encode('utf-8')).hexdigest()
    digitstocheck= hashlib.sha256("11111111".encode('utf-8')).hexdigest()
    digitsha1= hashlib.sha1("12345678".encode('utf-8')).hexdigest()
    hashalphanume1 = hashlib.sha256("azA24".encode('utf-8')).hexdigest()
    hashalphanume2 = hashlib.sha1("ahA23".encode('utf-8')).hexdigest()
    
    shabrute(hashstr,5,hashlib.sha256)
    shabrute(hashsha1,5,hashlib.sha1)
    digitsbrute(digitstocheck,8,hashlib.sha256)
    digitsbrute(digitsha1,8,hashlib.sha1)
    alphanumbrute(hashalphanume1,5,hashlib.sha256)
    alphanumbrute(hashalphanume2,5,hashlib.sha1)
if __name__ == "__main__":
    main()