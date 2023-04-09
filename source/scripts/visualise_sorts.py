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

# Get the sort name 
sort_name = latest_file.split(' ')[0]

# Create a scatter plot of the first column against the second column
plt.scatter(df.iloc[:, 0], df.iloc[:, 1])

# Detail the plot 
plt.xlabel('Size of dataset')
plt.ylabel('Execution time (s)')
plt.title(sort_name)

# Set the name of the visualisation and its path 
vis_name = latest_file.rstrip('.csv') + '.png'
vis_path = os.path.join(results_dir, vis_name)

# Save then show the plot 
plt.savefig(vis_path, dpi = 500, bbox_inches = 'tight')
plt.show()



# TO DO: 
# 1. Move import statement 
# 2. Complete getGrowthRate() function 
# 3. Use best model to plot growth rate

X = df.iloc[:,0].to_numpy().reshape(-1,1)
y = df.iloc[:,1].to_numpy().reshape(-1,1)

from growth_rate import get_growth_rate

get_growth_rate(X, y)

     













