import matplotlib.pyplot as plt
import numpy as np

cf_0 = np.genfromtxt('./data/communication_file_time_data.csv', delimiter=',', names=True)
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
