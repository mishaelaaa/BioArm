import pandas as pd

read_file = pd.read_csv(r'communication_file_1.txt')
read_file.to_csv(r'communication_file_1.csv', index=None)
