

# A Fibonacci sequence is the next number in the sequence is the sum of the previous two numbers
# In maths it is called a recurance relation, meaning that each term of the sequence is a function
# of the preceding terms 
# A factorial is the product of all the integers from one to (x) 6 = 1*2*3*4*5*6 = 720

def fibonacci_sequence_code(n):
    if n <= 1:
        return n
    else:
        return(fibonacci_sequence_code(n-1) + fibonacci_sequence_code(n-2))

nterms = 10

if nterms <= 0:
    print ("Please enter a positive integer")
else:
    print("This is the fibonacci sequence:")
    for i in range(nterms):
        print(fibonacci_sequence_code(i))
