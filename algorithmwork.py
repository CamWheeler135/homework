
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
d = 10
ads_selected =[]
total_reward = 0 
for n in range (0, N):
    ad = random.randrange(d)
    ads_selected.append(ad)
    reward = dataset.values[n, ad]
    total_reward = total_reward + reward

print(total_reward)