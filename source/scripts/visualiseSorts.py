import os
import datetime
import pandas as pd
import matplotlib.pyplot as plt


ERR_FILE = "error_log.txt"

# Get the directory containing the script file
script_dir = os.path.dirname(os.path.abspath(__file__))

# Set the results directory as a subdirectory of the parent directory
results_dir = os.path.join(os.path.dirname(script_dir), 'results')

# Find the most recent CSV file in the specified folder
files = [f for f in os.listdir(results_dir) if f.endswith('.csv')]
if len(files) == 0:
    with open(ERR_FILE, "a+") as error_file:
        error_file.write(f'{datetime.datetime.now()}: No CSV files found in {results_dir}')
    exit(-1)
latest_file = files[len(files)-1]
csv_path = os.path.join(results_dir, latest_file)

# Load the data from the CSV file into a Pandas dataframe
df = pd.read_csv(csv_path)

# Create a scatter plot of the first column against the second column
plt.scatter(df.iloc[:, 0], df.iloc[:, 1])

# Show the plot
plt.show()
