import os
import re


# a is larger than b
def findMissingChar(a,b):
    for c in a:
        if (b.find(c) == -1):
            return c
    
    return "z"

inFile = open("input.txt", 'r')

sum = 0


for l in inFile:
    digit_map = ["z","z","z","z","z","z","z","z","z","z"]
    display = []
    match = re.search("^(.*) \| (.+)$", l)

    if match != None:
        mapped = match.group(1).split(" ")
        digits = match.group(2).split(" ")

        for d in digits:
            display.append(d)

        for m in mapped:
            if (len(m) == 2):
                digit_map[1] = m
            elif (len(m) == 3):
                digit_map[7] = m
            elif (len(m) == 4):
                digit_map[4] = m
            elif (len(m) == 7):
                digit_map[8] = m

        c_dig = "z"
        e_dig = "z"
        for m in mapped:
            if (len(m) == 6):
                for c in digit_map[1]:
                    if (m.find(c) == -1):
                        digit_map[6] = m
                        c_dig = c

        for m in mapped:
            if (len(m) == 5):
                if (m.find(c_dig) == -1):
                    digit_map[5] = m
                    e_dig = findMissingChar(digit_map[6], digit_map[5])

        for m in mapped:
            if (len(m) == 6):
                if (m.find(e_dig) == -1):
                    digit_map[9] = m
                else:
                    if (m != digit_map[6]):
                        digit_map[0] = m
        
        f_dig = findMissingChar(digit_map[1], c_dig)

        for m in mapped:
            if (len(m) == 5):
                if (m.find(f_dig) == -1):
                    digit_map[2] = m
                else:
                    if (m != digit_map[5]):
                        digit_map[3] = m
        
        for i in range(10):
            t = ''.join(sorted(digit_map[i]))
            digit_map[i] = t
            
        factor = 3
        for d in display:
            t = ''.join(sorted(d))

            dig = -1
            for i in range(10):
                if (digit_map[i] == t):
                    dig = i * (10 ** factor)
            
            sum += dig
            factor -= 1

print(sum)
        



