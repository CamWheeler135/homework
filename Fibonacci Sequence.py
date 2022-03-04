

# A Fibonacci sequence is the next number in the sequence is the sum of the previous two numbers
# In maths it is called a recurance relation, meaning that each term of the sequence is a function
# of the preceding terms 
# A factorial is the product of all the integers from one to (x) 6 = 1*2*3*4*5*6 = 720

from optparse import Values
import string

def fibonacci_sequence_code(n):
    if n <= 1:
        return n
    else:
        return(fibonacci_sequence_code(n-1) + fibonacci_sequence_code(n-2))
        
nterms = 10
every_second_number = []

if nterms <= 0:
    print ("Please enter a positive integer")
else:
    print("This is the fibonacci sequence:")
    for i in range(nterms):
        print(fibonacci_sequence_code(i))
        every_second_number.append(fibonacci_sequence_code(i))


print(every_second_number[::2])


# Program a list from 1 to 100
# If the number divides by 3 or contains 3 = chip
# If the number divides by 5 or contains 5 = chop
# Change it to a string then we check for symbol if the string contains the symbol then we need to place chip or chop depending on the symbol.

number_list = list(range(1, 100))

for i in range(len(number_list)):
    if i % 3 == 0 and i % 5 == 0:
        print(i, "ChipChop")
    elif i % 5 == 0:
        print(i, "Chop")
    elif i % 3 == 0:
        print(i, "Chip")
    else:
        print(i)

number_list = str
# Changing number list into a string 

# We need to scan the string now, and check if the list contains the symbol 

# Depending on the value we need to print chip or chop
