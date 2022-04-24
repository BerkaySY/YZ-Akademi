sizeControl = False
inpControl = False
while sizeControl == False:
    arraySize = int(input("Please enter count of the legos heights(You have to enter between 1 and 100000) : "))
    if arraySize <= 10 ** 5 and arraySize >= 1:
        sizeControl = True
    else:
        print("You have to enter between 1 and 100000!!!")

while inpControl == False:
    heights = list(map(int,input("Please enter heights of legos (You have to enter between 1 and 100000 : ").split(' ')[:arraySize]))
    for i in heights:
        if i >= 1 and i <= 10 ** 5:
            inpControl = True
        else:
            inpControl = False
            print("You have to enter between 1 and 100000!!!")
            

def findMaxValue():
    max = heights[0]
    for i in heights:
        if i > max:
            max = i
    return max

def areHeightsSame():
    result = all(height == heights[0] for height in heights)
    if result:
        return True
    else:
        return False

def minEnergyCalc():
    ballEnergy = findMaxValue()
    while ballEnergy >= 1:
        newEnergy = ballEnergy
        for i in range(arraySize):
            if newEnergy >= heights[i]:
                newEnergy += (newEnergy - heights[i])
            elif newEnergy < heights[i]:
                newEnergy -= (heights[i] - newEnergy)

            if newEnergy < 0:
                break
            if i == (arraySize - 1) and newEnergy >= 0:
                if areHeightsSame() == True:
                    if heights[0] <= arraySize:
                        minEnergy = ballEnergy
                    else:
                        minEnergy = ballEnergy - 1
                else:
                    minEnergy = ballEnergy
            
        if minEnergy > ballEnergy:
            print("The Minimum Starting Ball Energy: " + str(minEnergy))
            break
        ballEnergy -= 1

minEnergyCalc()