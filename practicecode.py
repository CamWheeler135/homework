from itertools import combinations_with_replacement
from operator import getitem
from unicodedata import numeric
from xml.dom.minidom import Element

print ("Hello World")
print ("My name is Cameron")


'''Character Input'''

name = input("What is your name?: ")
print ("Your name is " + name)
age = input ("How old are you?: ")
age = int(age)
print (age * 10)

'''Odd or Even'''

number = input("Tell me a number: ")
number = int(number)
mod = number % 2
if mod > 0:
    print ("This is an odd number")
else:
    print ("You picked an even number")

'''List Less Than Ten'''
number_list = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
for elements in number_list:
    if elements <=5:
        print(elements)

'''Divisors'''

num = input("Please select a number: ")
num = int(num)
listRange = list(range(1,num+1))

divisorList =[]

for number in listRange:
    if num % number == 0:
        divisorList.append(number)

print (divisorList)

'''This is a change'''