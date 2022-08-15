import time
import serial
import serial.tools.list_ports

# Find the USB port we are on
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

arduino_data = [] # declare a list
# open serial port
# device = serial.Serial(thePort, 115200)
device = serial.Serial()
device.baudrate = 115200
device.port = thePort
device.open()
# time.sleep(5)
# device.reset_input_buffer()
# input_data=device.readline()

i = 0
while (True):
    if device.isOpen():
        i += 1
        # input_data=device.readline().strip().decode("utf-8")
        try:
            input_data = device.readline()
            # print(input_data)
            if input_data:
                arduino_data.append(input_data) # Append a data to your declared list
                print(input_data)
        except UnicodeDecodeError as e:
                print(e)
                print(input_data)
        except KeyboardInterrupt:
            print("\nexiting program ", i, " tests")
            device.close()
            exit(0)
