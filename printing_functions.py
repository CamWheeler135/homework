#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# Setting up a funtion that prints the models
def print_models(unprinted, printed):
    '''
    Simulate printing each desing, until none are left.
    Move each desing to printed after printing.
    '''
# Code that runs when the function is called
    while unprinted:
        current_design = unprinted.pop()
        print(f'Printing model: {current_design}')
        printed.append(current_design
                      )
# Setting up a function that shows the completed models
def show_completed_models(printed):
    '''Show all the models that were printed'''
# Code that runs when the function is called
    print("\nThe following models have been printed")
    for design in printed:
        print(design)

