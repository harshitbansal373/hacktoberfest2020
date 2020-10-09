############### Queue Implementation ############################
"""
queue: implemented as list
front: integer having position of first (frontmost) element in queue
rear: integer having position of last element in queue
"""
def cls():
    print("\n" * 100)
def isEmpty( Qu ):
    if Qu == []:
        return True
    else:
        return False
def Enqueue(Qu, item):
    Qu.append(item)
    if len(Qu) == 1:
        front = rear = 0
    else:
        rear = len(Qu) -1
def Dequeue(Qu):
    if isEmpty(Qu):
        return "Underflow"
    else:
        item = Qu.pop(0)
    if len(Qu) == 0:
        front = rear = None
    return item
def Peek(Qu):
    if isEmpty(Qu):
        return "Underflow"
    else:
        front = 0
    return Qu[front]
def Display(Qu):
    if isEmpty(Qu):
        print("Queue Empty!")
    elif len(Qu) == -1:
        print(Qu[0], "<==front,rear")
    else:
        front = 0
        rear = len(Qu) -1
        print(Qu[front], "<-front")
        for a in range(1, rear):
            print(Qu[a])
            print(Qu[rear], "<-rear")
#__main__program
queue = []
front = None
while True:
    cls()
    print("QUEUE OPERATIONS")
    print("1. Enqueue")
    print("2. Dequeue")
    print("3. Peek")
    print("4. Display queue")
    print("5. Exit")
    ch = int(input("Enter your choice between (1-5):"))
    if ch == 1:
        item = int(input("Enter item:"))
        Enqueue(queue, item)
        input("Press Enter to continue:")
    elif ch == 2:
        item = Dequeue(queue)
        if item == "Underflow":
            print("Underflow! Queue is empty!")
        else:
            print("Dequeue-ed item is", item)
        input("Press Enter to Continue....")
    elif ch == 3:
        item = Peek(queue)
        if item == "Underflow":
            print("Queue is empty!")
        else:
            print("Foremost item is", item)
        input("Press Enter to Contine.....")
    elif ch == 4 :
        Display(queue)
        input("Press Enter to Continue....")
    elif ch == 5:
        break
    else:
        print("Invalid Choice!")
        input("Press Enter to Continue...")
    
    
