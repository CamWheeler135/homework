#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# Setting up the function
def make_pizza(sauce, *toppings):
    '''Making a pizza with a specific sauce'''
#   Code that runs when we call the function
    print(f"\nMaking the pizza you ordered with {sauce} sauce the following toppings.")
    for topping in toppings:
        print(topping)

