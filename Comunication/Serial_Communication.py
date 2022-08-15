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
textfile = open("a_file.txt", "w") # declare file for writing

device = serial.Serial()
device.baudrate = 115200
device.port = thePort
device.open()

i = 0
while (True):
    if device.isOpen():
        i += 1
        try:
            input_data = device.readline()
            if input_data:
                arduino_data.append(input_data) # Append a data to your declared list
                for input_data in arduino_data:
                    # type : string
                    textfile.write(str(input_data) + '\n')
                    #   textfile.write(str(input_data).encode())
                    #   TypeError: write() argument must be str, not bytes
                    #textfile.write(input_data)
                    #textfile.write("\n".encode("utf-8"))
                print(input_data)
        except UnicodeDecodeError as e:
                print(e)
                print(input_data)
        except KeyboardInterrupt:
            print("\nexiting program ", i, " tests")
            device.close()
            textfile.close()
            print('Closed file')
            exit(0)


