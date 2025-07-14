class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
    def insert(self,data):
        if self.data:
            if data<self.data:
                if self.left is None:
                    self.left=Node(data)
                else:
                    self.left.insert(data)
            else:
                if self.right is None:
                    self.right=Node(data)
                else:
                    self.right.insert(data)
def inorder(root):
    if root:
        inorder(root.left)
        print(root.data,end=" ")
        inorder(root.right)

def height(root):
    if root is None:
        return 0
    return 1+max(height(root.left),height(root.right))
    # else:
    #     lh=height(root.left)
    #     rh=height(root.right)
    #     if(lh>rh):
    #         return 1+lh
    #     else:
    #         return 1+rh
    
    
def level(root):
  h=height(root)
  for i in range(1,h+1):
    curr(root,i)

def curr(root,l):
  if root is None:
    return 0
    
  elif l==1:
    print(root.data,end=" ")
  
  else:
    curr(root.left,l-1)
    curr(root.right,l-1)
    
def zigzag(root):
    h=height(root)
    f=True
    for i in range(1,h+1):
        curs(root,i,f)
        f= not f
        
def curs(root,l,f):
    if root is None:
        return 0
    elif(l==1):
        print(root.data,end=" ")
    else:
        if(f):
            curs(root.left,l-1,f)
            curs(root.right,l-1,f)
        else:
            curs(root.right,l-1,f)
            curs(root.left,l-1,f)
            
def minv(root):
    if root is None:
        return 0
    else:
        while(root.left):
            root=root.left
    return root.data
    
    
    
def maxv(root):
    if root is None:
        return 0
    else:
        while(root.right):
            root=root.right
            
    return root.data
    
    
n1=Node(27)
n1.insert(14)
n1.insert(35)
n1.insert(10)
n1.insert(19)
n1.insert(31)
n1.insert(42)
inorder(n1)
h=height(n1)
print("\nheight is: ",h)

print("Level order: ")
lv=level(n1)

print("\nzigzag: ")
zigzag(n1)

mins=minv(n1)
maxs=maxv(n1)

print("\nMin and Max value is",mins,":",maxs)


