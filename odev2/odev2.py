import sys

hourList = ["one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"]
minuteList = ["one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine","half"]

def timeInWords(h,m):
    if h == 0:
        h = 12
    if h > 12:
        h %= 12
    
    if m == 0:
        print(hourList[h - 1] + " o'clock")
    elif m == 1:
        print(minuteList[m - 1] + " " + "minute past " + hourList[h - 1])
    elif m == 30 or m == 15:
        print(minuteList[m - 1] + " " + "past " + hourList[h - 1])
    elif m < 30:
        print(minuteList[m - 1] + " " + "minutes past " + hourList[h - 1])
    
    if m > 30:
        m = 60 - m
        if m == 15:
            print(minuteList[m - 1] + " " + "to " + hourList[h])
        elif m == 1:
            print(minuteList[m - 1] + " " + "minute to " + hourList[h])
        else:
            print(minuteList[m - 1] + " " + "minutes to " + hourList[h])


while True:   
    hour = int(input("Please input a hour between 0 and 23 : "))
    if hour >= 0 and hour < 24:
        break
    else:
        print("You have to input a hour between 0 and 23 !!!")
        sys.exit()
        
while True:
    minute = input("Please input a minute between 00 and 59 : ")
    if minute[0] == '0':
        minute = int(minute[1])
    elif minute[0] != '0':
        minute = int(minute)
    
    if minute <= 59 and minute >= 0:
        break
    else:
        print("You have to input a minute between 00 and 59 !!!")
        sys.exit()
  
timeInWords(hour,minute)







