sizeControl = False
inpControl = False
while sizeControl == False:
    arraySize = int(input("Please input count of the lego's heights(You have to input between 1 and 100000) : "))
    if (arraySize <= 10 ** 5) and (arraySize >= 1):
        sizeControl = True
    else:
        print("You have to input between 1 and 100000!!!")

while inpControl == False:
    heights = list(map(int,input("Please input heights of lego (You have to input between 1 and 100000 : ").split(' ')[:arraySize]))
    for i in heights:
        if i >= 1 and i <= 10 ** 5:
            inpControl = True
        else:
            inpControl = False
            print("You have to input between 1 and 100000!!!")
            break

def findMaxValue():
    max = heights[0]
    for i in heights:
        if i > max:
            max = i
    return max

def checkArr():
    result = all(element == heights[0] for element in heights)
    if(result):
        return True
    else:
        return False

def minEnergyCalc():
    ballEnergy = findMaxValue()
    while ballEnergy >= 1:
        newEnergy = ballEnergy
        for i in range(arraySize):
            if newEnergy >= heights[i]:
                newEnergy = newEnergy + (newEnergy - heights[i])
            elif newEnergy < heights[i]:
                newEnergy = newEnergy - (heights[i] - newEnergy)

            if newEnergy < 0:
                break
            if i == (arraySize - 1) and newEnergy >= 0:
                if checkArr() == True:
                    if heights[0] <= arraySize:
                        minEnergy = ballEnergy
                    else:
                        minEnergy = ballEnergy - 1
                else:
                    minEnergy = ballEnergy
            
        if minEnergy > ballEnergy:
            print(minEnergy)
            break
        ballEnergy -= 1

minEnergyCalc()