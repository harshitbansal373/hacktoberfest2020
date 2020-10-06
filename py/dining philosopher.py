n=int(input("Enter the number of philosophers: "))
state=[0]*n
while(1):
    pid = int(input(f"Enter the philosopher id 0-{n-1} :"))
    if(pid>=n):
        print("index out of range\n")
        continue
    else:
        choice=int(input("1-Eat\n2-Think\n3.Exit\nEnter your choice:"))
        if(choice==1):
            state[pid]=1
            if(state[(pid+(n-1))%n]!=2 and state[pid]==1 and state[(pid+1)%n]!=2):
                state[pid]=2
                print(f"Philosopher {pid} is eating")
            else:
                print(f"Philosopher {pid} Can't eat")
        elif(choice==2):
            state[pid]=0
            print(f"Philosopher {pid} is Thinking")
            a=(pid+(n-1))%n
            b=(pid+1)%n
            if(state[(a+(n-1))%n]!=2 and state[a]==1 and state[(a+1)%n]!=2):
                state[a]=2
                print(f"Philosopher {a} is Eating")
           # else:
            #    print(f"Philosopher {a} Can't eat")'''
            if(state[(b+(n-1))%n]!=2 and state[b]==1 and state[(b+1)%n]!=2):
                state[b]=2
                print(f"Philosopher {b} is Eating")
           #''' else:
            #    print(f"Philosopher {b}Can't eat")'''
        else:
            exit()