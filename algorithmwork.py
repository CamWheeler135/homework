
from cProfile import run
from gettext import install
import imp

'''Importing libraries'''

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

'''Importing the dataset'''

dataset = pd.read_csv("Ads_Optimisation.csv")

'''Implementing Random Selection'''
'''Randomly showing user advert, if they click, we get reward (+1)'''
'''Ensure we know exactly what we are coding!!!!!!!!!!!!!!!!!!!!!!'''

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

    '''Take and store the total reward, reset total reward, run again'''

    graph_random.append(total_reward)
    total_reward = 0
        
print(total_reward)
print (graph_random)

'''Plotting results from 10 runs'''

run_number = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

plt.scatter(run_number, graph_random)
plt.xticks(run_number) ### unsure of this but it seems to work, without it the x values go up in 2. 
plt.ylabel("Random Selection Reward")
plt.xlabel("Run Number")
plt.title("Random Selection Rewards")
plt.show()

'''Coding epsilon greedy algorithm'''

import math 
 

# choose epsilon expoloration probability 
# choose n (number of iterations)
# for i = 1 to n do: 
    # p = pick a random number from 0 to 1 
    # if p < epsilone:
        # current_banit.pull_arm

# reward = current_banit.pull_arm()
# update estimation for what rewards the curren bandit gives -0