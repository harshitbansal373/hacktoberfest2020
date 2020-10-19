import sys
sys.stdout=open('IO/output.txt','w')
sys.stdin=open('IO/input.txt','r')

from collections import deque
 
class Node:
   def __init__(self,data):
       self.data = data
       self.left = None
       self.right = None

class Pair:
    def __init__(self):
        self.height=0
        self.diameter=0      

class HBPair:
    def __init__(self):
        self.height = 0
        self.balance = True

class SumPair:
    def __init__(self):
        self.branchSum = 0
        self.maxSum = 0

def InOrder(root):
   if root:
       InOrder(root.left)
       print (root.data,end=" ")
       InOrder(root.right)

def PreOrder(root):
   if root:
       print (root.data,end=" ")
       PreOrder(root.left)
       PreOrder(root.right)

def PostOrder(root):
   if root:
       PostOrder(root.left)
       PostOrder(root.right)
       print (root.data,end=" ")

#making the tree 
def BuildTree(l):
    data = l.pop(0)
    if (data == -1):
        return None
    root = Node(data)
    root.left = BuildTree(l)
    root.right = BuildTree(l)
    return root

def height(root):
    if root == None :
        return 0
    ls = height(root.left)
    rs  = height(root.right)
    return max(ls,rs)+1

def KthLevel(root, k):
    if (root == None):
        return
    if (k ==1):
        print(root.data,end=' ')
        return
    KthLevel(root.left, k-1)
    KthLevel(root.right, k-1)
    return

def bfs(root):
    queue = deque()
    queue.append(root)
    queue.append(None)
    while(len(queue)>0):
        node = queue.popleft()
        if(node == None):
            print()
            if(len(queue)>0):
                queue.append(None)
        else:
            print(node.data,end=',')
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right) 
    return

def countNode(root):
    if (root == None):
        return 0
    return 1 + countNode(root.left) + countNode(root.right)

def diameter(root):
    if (root == None):
        return 0
    h1 = height(root.left)
    h2 = height(root.right)
    op1 = h1+h2
    op2 = diameter(root.left)
    op3 = diameter(root.right)
    return max(op1,op2,op3)

def fast_diameter(root):
    p = Pair()
    if (root == None):
        p.height=0
        p.diameter=0
        return p
    left = fast_diameter(root.left)
    right = fast_diameter(root.right)

    p.height = max(left.height,right.height) + 1
    p.diameter = max(left.height+right.height, left.diameter, right.diameter)
    return p

def SumReplacement(root):
    if (root == None):
        return 0
    if (root.left == None and root.right == None):
        return root.data    
    
    leftSum = SumReplacement(root.left)
    rightSum = SumReplacement(root.right)

    temp = root.data    
    root.data = leftSum + rightSum
    return temp + root.data

def isHeightBalance(root):
    p = HBPair()
    if ( root == None):
        p.height = 0
        p.balance = True
        return p
    #Recursive -- PostOrder
    leftSide = isHeightBalance(root.left)
    rightSide = isHeightBalance(root.right)
    p.height = max(leftSide.height,rightSide.height)+1
    if (abs(leftSide.height-rightSide.height)<=1 and leftSide.balance and rightSide.balance):
        p.balance = True
    else:
        p.balance = False
    return p 

def BuildTreeFromArray(l,s,e):
    if(s>e):
        return None
    mid = (s+e)//2
    root = Node(l[mid])
    root.left = BuildTreeFromArray(l,s,mid-1)
    root.right = BuildTreeFromArray(l,mid+1,e)
    return root

i=0
def BuildTree_PreInOrder(inorder,pre,s,e):
    #Base Case
    global i
    if(s>e):
        return None
    #Recursive Case
    root = Node(pre[i])
    index = inorder.index(pre[i])

    i+=1
    root.left = BuildTree_PreInOrder(inorder,pre,s,index-1)
    root.right = BuildTree_PreInOrder(inorder,pre,index+1,e)
    return root

def RightView(root,level,maxlevel):
    if (root == None):
        return
    if (maxlevel[0] < level):
        #discovered a new node
        print(root.data)
        maxlevel[0] = level
    
    RightView(root.right,level+1,maxlevel)
    RightView(root.left,level+1,maxlevel)

def PrintAtDistanceK(root, target, k):
    #Base Case
    if (root == None):
        return -1
    #Reach the Target
    if (root == target):
        KthLevel(target, k+1)
        return 0
    #Next-Step Ancestor
    DL = PrintAtDistanceK(root.left, target, k)
    if(DL != -1):
        if(DL+1 == k):
            print(root.data,end=' ')
        else:
            KthLevel(root.right, k-2-DL+1)
        return DL+1
    DR = PrintAtDistanceK(root.right, target, k)
    if(DR != -1):
        if(DR+1 == k):
            print(root.data,end=' ')
        else:
            KthLevel(root.left, k-2-DL+1)
        return DR+1
    return -1

#Lowest Common Ancestor
def lca(root, a, b):
    if (root == None):
        return None
    if (root.data == a or root.data == b):
        return root
    #Search in left & Right
    leftAns = lca(root.left, a, b)
    rightAns = lca(root.right, a, b)

    if (leftAns!=None and rightAns!=None):
        return root
    if (leftAns!=None):
        return leftAns
    return rightAns

def MaxSumN2N(root):
    p = SumPair()
    if (root == None):
        return p
    
    ls = MaxSumN2N(root.left)
    rs = MaxSumN2N(root.right)

    op1 = root.data
    op2 = root.data + ls.branchSum 
    op3 = root.data + rs.branchSum
    op4 = root.data + ls.branchSum + rs.branchSum

    current_root_sum = max(op1,op2,op3,op4)
    p.branchSum = max(ls.branchSum,rs.branchSum)+root.data
    p.maxSum = max(ls.maxSum,rs.maxSum,current_root_sum)
    return p

def Search(root,key,level):
    if (root == None):
        return -1
    if ( root.data == key):
        return level
    l = Search(root.left,key,level+1)
    if(l!=-1):
        return l
    return Search(root.right,key,level+1)

def DistanceN2N(root,a,b):
    lca_root = lca(root,a,b)
    d1 = Search(lca_root,a,0)
    d2 = Search(lca_root,b,0)
    return d1+d2

#--- Driver Code ---------------------------
if __name__ == '__main__':
    
    '''
    l = list(map(int,input().split()))
    inorder = list(map(int,input().split()))
    pre = list(map(int,input().split()))

    
    p = Pair()
    print("Pre order Traversal: ",end=" ")
    PreOrder(root)
    print()
    print("In order Traversal: ",end=" ")
    InOrder(root)
    print()
    print("Post order Traversal: ",end=" ")
    PostOrder(root)
    print()
    print("height: ",end=" ")
    print(height(root))
    print("Kth Level: ",end=" ")
    KthLevel(root,3)
    print()
    print("BFS Traverse: ",end=" ")
    bfs(root)
    print()
    print("No of Nodes: ",end=" ")
    print(countNode(root))
    #print(diameter(root))
    p = fast_diameter(root)
    print("height:",p.height)
    print("diameter:",p.diameter)
    print("---Sum Replacement----")
    print("Before:")
    bfs(root)
    print()
    print("After:")
    SumReplacement(root)
    bfs(root)
    print()
    print("--Height Balance--")
    if(isHeightBalance(root).balance):
        print("YES")
    else:
        print("NO")
    
    print("-- Build Tree with Array-- ")
    root = BuildTreeFromArray(l,0,len(l)-1)
    bfs(root)
    
    print("-- Build Tree from Inorder & PreOrder --")
    print("inorder",inorder)
    print("preorder",pre)
    root = BuildTree_PreInOrder(inorder,pre,0,len(pre)-1)
    print("TREE :")
    bfs(root)
    print("Right View")
    maxlevel = [-1]
    RightView(root,0,maxlevel)
    
    root = BuildTree(l)
    bfs(root)
    target = root.left.left
    print("K distance Node ::")
    PrintAtDistanceK(root, target, 3)
    print("LCA ::")
    lca_node = lca(root,6,9)
    print(lca_node.data)

    print("Max Sum Branch : ",MaxSumN2N(root).maxSum)

    a,b=6,9
    print("Distance btw",a," and ",b,"is : ",DistanceN2N(root,a,b))
    a,b=8,1
    print("Distance btw",a," and ",b,"is : ",DistanceN2N(root,a,b))
    '''
    l = list(map(int,input().split()))
    root = BuildTree(l)
    bfs(root)
    print("---------")
    KthLevel(root,3)
    print('count',countNode(root))
    