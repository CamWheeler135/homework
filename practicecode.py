from audioop import reverse
from itertools import combinations_with_replacement
from operator import getitem
from unicodedata import numeric
from xml.dom.minidom import Element
import random

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

'''List Overlap'''

print("List Overlap")

A = [1, 2, 3, 4, 5, 7, 8, 9, 12, 15, 124]
B = [1, 2, 3, 4, 6, 7, 8, 13, 15, 135]

print(list(set(A).intersection(B)))

'''String Lists'''

string = input("Please type in a word: ")

if string == string[::-1]:
    print("This is a palindrom")
else:
    print("This is not a palindrom")

'''Rock Paper Sissors'''

while True:
    player1  = input("player 1 choose, rock, paper or scissors?: ")
    player2 = input("player 2 choose rock, paper or scissors?: ")

    if player1 == player2:
        print("The game is a draw")
    elif player1 == "rock" and player2 == "scissors":
        print("Player 1 wins")
    elif player1 == "scissors" and player2 == "rock":
        print("Player 2 wins")
    elif player1 == "paper" and player2 == "rock":
        print("Player 1 wins")
    elif player1 == "rock" and player2 == "paper":
        print("Player 2 wins")
    elif player1 == "paper" and player2 == "scissors":
        print("Player 2 wins")
    elif player1 == "scissors" and player2 == "paper":
        print("Player 1 wins")
    else:
        print("Ensure you have chosen rock, paper or scissors!")
    
    want_to_quit = input("Do you want to quit or play again?: ")
    
    if want_to_quit == "quit":
        break
    else:
        ("Time to play again!")

'''Guessing Game One'''

random_number = random.randint (1,9)

print (random_number)