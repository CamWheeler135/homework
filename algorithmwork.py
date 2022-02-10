
from cProfile import run
from gettext import install

'''Importing libraries'''

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

'''Importing the dataset'''

dataset = pd.read_csv("Ads_Optimisation.csv")

'''Implementing Random Selection'''
'''Randomly showing user advert, if they click, we get reward (+1)'''

import random 
N = 10000
d = 5
ads_selected =[]
total_reward = 0
graph_random = []

for x in range (0, 10):
    for n in range (0, N):
        ad = random.randrange(d)
        ads_selected.append(ad)
        reward = dataset.values[n, ad]
        total_reward = total_reward + reward

    '''Take and store the total reward, reset total reward, run again '''

    graph_random.append(total_reward)
    total_reward = 0
        
print(total_reward)
print (graph_random)

'''Plotting results from 10 runs'''

run_x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
reward_from_run_y = [graph_random]

plt.plot(run_x, reward_from_run_y)

plt.show()


