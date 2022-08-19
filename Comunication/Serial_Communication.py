''''
https://pythonforundergradengineers.com/python-arduino-potentiometer.html
'''

''''
timestamp_csv.py
YOUR_CSV_FILE.csv

https://www.kaggle.com/code/sam1o1/eeg-signal-processing/notebook


others 
https://www.kaggle.com/code/afajohn/cnn-lstm-for-signal-classification-lb-0-513
https://www.kaggle.com/code/ashishpatel26/redesign-stacked-lstm-advance-parameter-tuning?scriptVersionId=10110656
https://www.kaggle.com/code/braquino/5-fold-lstm-attention-fully-commented-0-694/notebook
https://www.kaggle.com/code/theoviel/fast-fourier-transform-denoising/notebook

https://colab.research.google.com/gist/pati-dev/20ced4b4ecc78fb43f0c26e318fe00a1/speech-denoising-using-lstm.ipynb

images :
https://www.datacamp.com/tutorial/autoencoder-keras-tutorial
speach :
https://gist.github.com/pati-dev/20ced4b4ecc78fb43f0c26e318fe00a1

https://mne.tools/dev/auto_tutorials/intro/10_overview.html
https://mne.tools/stable/index.html
https://mne.tools/stable/install/index.html


https://www.tutorialexample.com/channel-attention-in-squeeze-and-excitation-se-block-explained-deep-learning-tutorial/

denoising input array jupyter notebook

'''

import time
import serial.tools.list_ports
import matplotlib.pyplot as plt
import csv
from datetime import datetime

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
# textfile = open("/data/communication_file.txt", "w")    # declare file for writing
# textfile = open("/data/communication_file_1.txt", "w")  # declare file for writing
# cvsfile = open("/data/communication_file_1.csv", "w")   # declare file for writing
cvsfile = open("./data/communication_file.csv", "w")   # declare file for writing
seperator = ','
i = 0

#while (True):
for i in range(1500000):
# for i in range(15000):
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
                # textfile.write(str(num) + '\n')
                cvsfile.write(str(i) + seperator + str(log_date) + seperator + str(log_time) + seperator + str(num) + '\n')
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
plt.plot(arduino_data)
plt.xlabel('Time')
plt.ylabel('EMG Reading Data')
plt.title('EMG Reading Data vs. Time')
# Saving the figure.
plt.savefig("/img/Serial_Communication_img.jpg")
# Saving figure by changing parameter values
plt.savefig("/img/Serial_Communication_img_1", facecolor='y', bbox_inches="tight",
            pad_inches=0.3, transparent=True)
plt.show()
