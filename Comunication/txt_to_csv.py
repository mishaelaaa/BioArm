import time
import serial.tools.list_ports
import matplotlib.pyplot as plt

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

cvsfile = open("communication_file_2.csv", "w")   # declare file for writing

seperator = ','

i = 0
for i in range(15000):
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
                arduino_data.append(num) # Append a data to your declared list
                print(num)
                cvsfile.write(str(i) + seperator + str(log_date) + seperator + str(log_time) + seperator + str(num) + '\n')
        except UnicodeDecodeError as e:
                print(e)
                print(input_data)
        except KeyboardInterrupt:
            print("\nexiting program ", i, " tests")
            device.close()
            cvsfile.close()
            print('Closed file')
            exit(0)
plt.plot(arduino_data)
plt.xlabel('Time')
plt.ylabel('EMG Reading Data')
plt.title('EMG Reading Data vs. Time')
# Saving the figure.
plt.savefig("Serial_Communication_img.jpg")
# Saving figure by changing parameter values
plt.savefig("Serial_Communication_img_1", facecolor='y', bbox_inches="tight",
            pad_inches=0.3, transparent=True)
plt.show()
