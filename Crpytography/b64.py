#review by maskit : 27.03.2023

import sys
def b64encode(s):
    i = 0
    base64 = ending = ''
    base64chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
  
  # Add padding if string is not dividable by 3
    pad = 3 - (len(s) % 3)
    if pad != 3:
        s += "\0" * pad
        ending += '=' * pad
  
  # Iterate though the whole input string
    while i < len(s):
        b = 0
    # Take 3 characters at a time, convert them to 4 base64 chars
        for j in range(0,3,1):
            n = ord(s[i])
            i += 1
  
      # Concatenate the three characters together 
            b += n << 8 * (2-j)
    
    # Convert the 3 chars to four Base64 chars
        base64 += base64chars[ (b >> 18) & 63 ]
        base64 += base64chars[ (b >> 12) & 63 ]
        base64 += base64chars[ (b >> 6) & 63 ]
        base64 += base64chars[ b & 63 ]
  # Add the actual padding to the end
    if pad != 3:
        base64 = base64[:-pad]
        base64 += ending
  
  # Print the Base64 encoded result
    return base64

def base64decode(s):
    i = 0
    base64 = decoded = ''
    base64chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
  
    if s[-2:] == '==':
        s = s[0:-2] + "AA"
        padd = 2
    elif s[-1:] == '=':
        s = s[0:-1] + "A"
        padd = 1
    else:
        padd = 0
  
    while i < len(s):
        d = 0
        for j in range(0,4,1): 
            d += base64chars.index( s[i] ) << (18 - j * 6)
            i += 1
    
        decoded += chr( (d >> 16 ) & 255 )
        decoded += chr( (d >> 8 ) & 255 )
        decoded += chr( d & 255 )
    decoded = decoded[0:len( decoded ) - padd]

    print (decoded)
