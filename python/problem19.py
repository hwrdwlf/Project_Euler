import time

start_time = time.time();
startYear = 1900;
endYear = 2001;
startMonth = 1;
endMonth = 13;
numOfSundays = 0;
dayList = [[0,0,0]];
for year in range(startYear, endYear):
    daysInMonth = 0;
    for month in range(1,13):
        if month in [4,6,9,11]:
            daysInMonth = 30;
        elif month == 2:
            if year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
                daysInMonth = 29;
            else:
                daysInMonth = 28;
        else:
            daysInMonth = 31;
        for day in range(1, daysInMonth + 1):
            dayList.append([year, month, day]);

sundayList = [];
for day in range(len(dayList)):
    if not (day - 6) % 7 and dayList[day][0] > 1900 and not dayList[day][2] - 1:
        sundayList.append(dayList[day])
print len(sundayList)
print("--- %s seconds ---" % (time.time() - start_time))



start_time = time.time();
import datetime
count = 0
for y in range(1901,2001):
    for m in range(1,13):
        if datetime.datetime(y,m,1).weekday() == 6:
            count += 1
print count
print("--- %s seconds ---" % (time.time() - start_time))