#Implemented in Python to abuse its natural bigint because 5000! is nasty in c++ without GMP
import math

def god(n):
    #greatest odd divisor
    pass

cache = {}
def factorial(n):
    return cache.setdefault(n,math.factorial(n))

def bi_co(n, k):
#    n_fact = 1
#    stored = 1
#    for i in range(1, n+1):
#        n_fact = n_fact * i 
#        if i == n-k:
#            stored = stored * n_fact
#        if i == k:
#            stored = stored * n_fact
#    return n_fact//stored
    return factorial(n)//(factorial(k)*factorial(n-k))

def catalan_number(n):
    return bi_co(2*n,n)//(n+1)

t = int(input())
while(t > 0):
    n = int(input())
    print(catalan_number(n))
    t = t - 1
