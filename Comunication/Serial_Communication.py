''''
https://pythonforundergradengineers.com/python-arduino-potentiometer.html
'''
import serial
import time
import io
import serial.tools.list_ports
import matplotlib.pyplot as plt
import cv2
import imageio

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
#textfile = open("communication_file.txt", "w")  # declare file for writing
textfile = open("communication_file_1.txt", "w")  # declare file for writing

i = 0
#while (True):
for i in range(1500000):
#for i in range(15000):
    if device.isOpen():
        i += 1
        try:
            input_data = device.readline()  # to reading
            if input_data:
                string = input_data.decode()
                num = int(string)
                print(num)
                arduino_data.append(num) # Append a data to your declared list
                textfile.write(str(num) + '\n')
        except UnicodeDecodeError as e:
                print(e)
                print(input_data)
        except KeyboardInterrupt:
            print("\nexiting program ", i, " tests")
            device.close()
            textfile.close()
            print('Closed file')
            exit(0)
# build the plot
data_file = plt.plot(arduino_data)
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
