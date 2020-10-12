############################ Stack Implementation #########################################
"""
Stack:implemented as a list
top:integer having position of top most element in the stack
"""
def isEmpty(stk):
    if stk == []:
        return True
    else:
        return False
def Push(stk, item):
    stk.append(item)
    top = len(stk) -1
def Pop(stk):
    if isEmpty(stk):
        return "Underflow"
    else:
        item = stk.pop()
        if len (stk)== 0:
            top = None
        else:
            top = len(stk) - 1
        return item
def Peek(stk):
    if isEmpty(stk):
        return "Underflow"
    else:
        top = len(stk) - 1
        return stk[top]
def Display(stk):
    if isEmpty(Stack):
        print("Stack empty")
    else:
        top = len(stk) -1
        print(stk[top], "<-top")
        for a in range(top-1,-1,-1):
            print(stk[a])
#__main__
Stack = [] # initially stack is empty
top = None
while True:
    print("STACK OPERATIONS")
    print("1. Push")
    print("2. Pop")
    print("3. Peek")
    print("4. Display Stack")
    print("5. Exit")
    ch = int(input("Enter your choice between(1-5):"))
    if ch == 1:
        item = int(input("Enter item:"))
        Push(Stack, item)
    elif ch == 2:
        item = Pop(Stack)
        if item == "Underflow":
            print("Underflow! Lack is empty")
        else:
            print("Popped item is",item)
    elif ch == 3:
        item = Peek(Stack)
        if item == "Underflow":
            print("Underflow! Stack is empty!")
        else:
            print("Topmost item is",item)
    elif ch == 4:
        Display(Stack)
    elif ch == 5:
        break
    else:
        print("Invalid Chioce!!")