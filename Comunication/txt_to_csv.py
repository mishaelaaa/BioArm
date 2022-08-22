import time
import serial.tools.list_ports
import matplotlib.pyplot as plt
import pandas as pd
import csv

cvsfile = open("./data/communication_file00_0.csv", "w")   # declare file for writing

plt.rcParams["figure.figsize"] = [10, 5]
plt.rcParams["figure.autolayout"] = True

# assign header columns
headerList = ['Time', 'Value']

# Find the USB port
commports = serial.tools.list_ports.comports()  # get possible ports
numPorts = len(commports)

if (numPorts == 0):
    print("No serial ports available\n\n")
    exit()
if (numPorts > 1):
    # Have user pick one
    portNum = 0
    for port in commports:
        print("port number ", portNum)
        print(port)
        portNum = portNum + 1
    usePort = int(input('enter port number to use 0-' + str(numPorts - 1) + ':'))
else:
    usePort = 0

thePort = commports[usePort][0]
print('using ', thePort, '\n')

device = serial.Serial()
device.baudrate = 115200
device.port = thePort
device.open()

time.sleep(2)
arduino_data = []  # declare a list

#plot the required data as X and Y axis.
x = []
y = []


seperator = ','
i = 0

cvsfile.write('Time' + seperator + 'Value' + '\n')

# for i in range(95000):
for i in range(950):
    if device.isOpen():
        i += 1
        try:
            input_data = device.readline()  # to reading
            if input_data:
                string = input_data.decode()
                num = int(string)
                arduino_data.append(num) # Append a data to your declared list
                print(num)
                # textfile.write(str(num) + '\n')

                log_time_date = time.localtime()                    # Get log date time from PC
                log_time = time.strftime("%H:%M:%S", log_time_date) # hh:mm:ss
                log_date = time.strftime("%d %B %Y", log_time_date) # dd MonthName Year
                log_data_time = log_date + ' ' + log_time

                # print(log_data_time)
                # cvsfile.write(str(i) + seperator + str(log_date) + seperator + str(log_time) + seperator + str(num) + '\n')
                cvsfile.write(log_time + seperator + str(num) + '\n')

        except UnicodeDecodeError as e:
                print(e)
                print(input_data)

        except KeyboardInterrupt:
            print("\nexiting program ", i, " tests")
            device.close()
            cvsfile.close()
            # textfile.close()
            print('Closed file')
            exit(0)

with open('./data/communication_file00_0.csv','r') as csv:
    lines = csv.reader(csv, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(int(row[1]))

plt.plot(x, y, color = 'g', linestyle = 'dashed',
         marker = 'o',label = "Weather Data")

plt.xticks(rotation = 25)
plt.xlabel('Dates')
plt.ylabel('Values')
plt.title('Weather Report', fontsize = 20)
plt.grid()
plt.legend()
plt.show()
