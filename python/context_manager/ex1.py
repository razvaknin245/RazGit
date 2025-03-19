fileone = open("readme.txt","r")
print(fileone.read().upper())
fileone.close()

with open("readme.txt","r")as f:
    data = f.read().upper()
    print(data)
    
