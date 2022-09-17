

from concurrent.futures import process
from math import ceil
import copy

inF = open("input_day9.txt", 'r')

hMap = [[int(i) for i in line if i != '\n'] for line in inF]


maxY = len(hMap[0])
maxX = len(hMap)

processed = copy.deepcopy(hMap)

basins = [0]
newBasin = -1

def makeBasin(basin, x, y):

        processed[x][y] = basin

        if ((x-1) >= 0):
            if (hMap[x-1][y] < 9) and (processed[x-1][y] >= 0):
                makeBasin(basin, x-1, y) 

        if ((x+1) < maxX):
            if (hMap[x+1][y] < 9) and (processed[x+1][y] >= 0):
                makeBasin(basin, x+1, y) 

        if ((y-1) >= 0):
            if (hMap[x][y-1] < 9) and (processed[x][y-1] >= 0):
                makeBasin(basin, x, y-1) 

        if ((y+1) < maxY):
            if (hMap[x][y+1] < 9) and (processed[x][y+1] >= 0):
                makeBasin(basin, x, y+1) 


sum = 0
for x in range(maxX):
    for y in range(maxY):
        p = int(hMap[x][y])

        lower = True

        if ((x-1) >= 0):
            if (p >= hMap[x-1][y]):
                lower = False 

        if ((x+1) < maxX):
            if (p >= hMap[x+1][y]):
                lower = False 

        if ((y-1) >= 0):
            if (p >= hMap[x][y-1]):
                lower = False 

        if ((y+1) < maxY):
            if (p >= hMap[x][y+1]):
                lower = False 

        if (lower):
            sum += p + 1


# part 2
        if (processed[x][y] >= 0):

            if (p == 9):
                processed[x][y] = 9
            else:
                makeBasin(newBasin, x, y)
                newBasin = newBasin - 1


print("\n")

basins = [len([c for row in processed for c in row if (c == -i) and (c != 9)]) for i in range(abs(newBasin))]
basins.sort(reverse=True)        
        


for x in processed:
    print(x)

print(basins)

mult = basins[0] * basins[1] * basins[2]
print ("Part 1 = " + str(sum))
print("Part 2 = " + str(mult))