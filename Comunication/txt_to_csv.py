import time
import serial.tools.list_ports
import matplotlib.pyplot as plt
import numpy as np

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
cvsfile0 = open("./data/communication_file_time_data0.csv" , "w")   # declare file for writing
cvsfile1 = open("./data/communication_file_time_data1.csv", "w")   # declare file for writing
cvsfile2 = open("./data/communication_file_time_data2.csv", "w")   # declare file for writing
cvsfile3 = open("./data/communication_file_time_data3.csv", "w")   # declare file for writing
cvsfile4 = open("./data/communication_file_time_data4.csv", "w")   # declare file for writing
cvsfile5 = open("./data/communication_file_time_data5.csv", "w")   # declare file for writing

seperator = ','
i = 0

cvsfile0.write ('Time' + seperator + 'Value' + '\n')
cvsfile1.write('Time' + seperator + 'Value' + '\n')
cvsfile2.write('Time' + seperator + 'Value' + '\n')
cvsfile3.write('Time' + seperator + 'Value' + '\n')
cvsfile4.write('Time' + seperator + 'Value' + '\n')
cvsfile5.write('Time' + seperator + 'Value' + '\n')

for i in range(95000):
    if device.isOpen():
        i += 1
        try:
            input_data = device.readline()  # to reading
            if input_data:
                log_time_date = time.localtime()                    # Get log date time from PC
                log_time = time.strftime("%H:%M:%S", log_time_date) # hh:mm:ss
                log_date = time.strftime("%d %B %Y", log_time_date) # dd MonthName Year

                string = input_data.decode()
                num = int(string)
                print(num)
                arduino_data.append(num) # Append a data to your declared list

                if i <= 15830 :
                    cvsfile0.write(str(log_time) + seperator + str(num) + '\n')
                elif 15830 < i <= 31660:
                    cvsfile1.write(str(log_time) + seperator + str(num) + '\n')
                elif 31660 < i <= 48490:
                    cvsfile2.write(str(log_time) + seperator + str(num) + '\n')
                elif 48490 < i <= 63320:
                    cvsfile3.write(str(log_time) + seperator + str(num) + '\n')
                elif 63320 < i <= 79150:
                    cvsfile4.write(str(log_time) + seperator + str(num) + '\n')
                else :
                    cvsfile5.write(str(log_time) + seperator + str(num) + '\n')

        except UnicodeDecodeError as e:
                print(e)
                print(input_data)

        except KeyboardInterrupt:
            print("\nexiting program ", i, " tests")
            device.close()
            cvsfile0.close()
            cvsfile1.close()
            cvsfile2.close()
            cvsfile3.close()
            cvsfile4.close()
            cvsfile5.close()
            # textfile.close()
            print('Closed file')
            exit(0)

cf_0 = np.genfromtxt('./data/communication_file_time_data0.csv', delimiter=',', names=True)
cf_1 = np.genfromtxt('./data/communication_file_time_data1.csv', delimiter=',', names=True)
cf_2 = np.genfromtxt('./data/communication_file_time_data2.csv', delimiter=',', names=True)
cf_3 = np.genfromtxt('./data/communication_file_time_data3.csv', delimiter=',', names=True)
cf_4 = np.genfromtxt('./data/communication_file_time_data4.csv', delimiter=',', names=True)
cf_5 = np.genfromtxt('./data/communication_file_time_data5.csv', delimiter=',', names=True)

plt.figure("cf_0")
for col_name in cf_0.dtype.names:
    plt.plot(cf_0[col_name], label=col_name)
plt.savefig("./img/communication_file_time_data_0", transparent=True)

plt.figure("cf_1")
for col_name in cf_1.dtype.names:
    plt.plot(cf_1[col_name], label=col_name)
plt.savefig("./img/communication_file_time_data_1", transparent=True)

plt.figure("cf_2")
for col_name in cf_2.dtype.names:
    plt.plot(cf_2[col_name], label=col_name)
plt.savefig("./img/communication_file_time_data_2", transparent=True)

plt.figure("cf_3")
for col_name in cf_3.dtype.names:
    plt.plot(cf_3[col_name], label=col_name)
plt.savefig("./img/communication_file_time_data_3", transparent=True)

plt.figure("cf_4")
for col_name in cf_4.dtype.names:
    plt.plot(cf_4[col_name], label=col_name)
plt.savefig("./img/communication_file_time_data_4", transparent=True)

plt.figure("cf_5")
for col_name in cf_5.dtype.names:
    plt.plot(cf_5[col_name], label=col_name)
plt.savefig("./img/communication_file_time_data_5", transparent=True)

plt.legend()
plt.show()

plt.figure("Total")
plt.plot(arduino_data)
plt.xlabel('Time')
plt.ylabel('EMG Reading Data')
plt.title('EMG Reading Data vs. Time')
plt.savefig("./img/communication_file_time_data", transparent=True)
plt.show()
