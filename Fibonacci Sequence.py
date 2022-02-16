

# A Fibonacci sequence is the next number in the sequence is the sum of the previous two numbers
# In maths it is called a recurance relation, meaning that each term of the sequence is a function
# of the preceding terms 

def recur_fibonacci(n):
    if n <= 1:
        return n
    else:
        return(recur_fibonacci(n-1) + recur_fibonacci(n-2))

nterms = 10

if nterms <= 0:
    print ("Please enter a positive integer")
else:
    print("This is the fibonacci sequence:")
    for i in range(nterms):
        print(recur_fibonacci(i))