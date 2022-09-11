import time
import serial.tools.list_ports
import matplotlib.pyplot as plt
import numpy as np
import csv
from datetime import datetime

plt.ion()
fig = plt.figure()

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

i=0
x=list()
y=list()
i=0

while True:    
    if device.isOpen():
        i += 1
        try:
            input_data = device.readline()  # to reading
            if input_data:
                string = input_data.decode()
                data = int(string)
                print(data)
    
                data = device.readline()
                print(data.decode())
                x.append(i)
                y.append(data.decode())

                plt.scatter(i, float(data.decode()))
                i += 1
                plt.show()
                plt.pause(0.0001)  # Note this correction

        except UnicodeDecodeError as e:
            print(e)
            print(input_data)

        except KeyboardInterrupt:
            print("\nexiting program ", i, " tests")
            device.close()
            print('Close')
            exit(0)
