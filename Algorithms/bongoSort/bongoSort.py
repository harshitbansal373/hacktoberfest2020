import random 

def bogoSort(a): 
    while (not is_sorted(a)): 
        shuffle(a)

def is_sorted(a): 
    for i in range(0, len(a)-1): 
        if (a[i] > a[i+1] ): 
            return False
    return True

def shuffle(a): 
    n = len(a) 
    for i in range (0,n): 
        r = random.randint(0,n-1) 
        a[i], a[r] = a[r], a[i]
