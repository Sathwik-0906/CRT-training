from collections import deque
class Node:
  def _init_(self,data):
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

def height(root):
  if root is None:
    return 0
  return 1+max(height(root.left),height(root.right))
         
             # else part for height

  # else:
  #   lh=height(root.left)
  #   rh=height(root.right)
  #   if(lh>rh):
  #     return 1+lh
  #   else:
  #     return 1+rh

# def level(root):
#   h=height(root)
#   for p in range(1,h+1):#(1,4) # 1,2,3
#     current(root,p) #(root,1)

# def current(root,l):#(root,1)
#   if root is None:
#     return 0
#   elif(l==1):
#     print(root.data,end=" ")
#   else:
#     current(root.left,l-1) # current(50,2) #c(25,1) #c(125,1)
#     current(root.right,l-1) #c(150,2) #c(75,1) #c(180,1)

def preorder(root):
  if(root):
    print(root.data,end=" ")
    preorder(root.left)
    preorder(root.right)

def inorder(root):
  if(root):
    inorder(root.left)
    print(root.data,end=" ")
    inorder(root.right)

def postorder(root):
  if(root):
    postorder(root.left)
    postorder(root.right)
    print(root.data,end=" ")


def zigzag(root):
  h=height(root)
  f=True
  for p in range(1,h+1):
    current(root,p,f)
    f=not f

def current(root,l,f):#(root,1,false)
  if root is None:
    return 0
  elif(l==1):
    print(root.data,end=" ")
  else:
    if(f):
      current(root.left,l-1,f) # current(50,2) #c(25,1) #c(125,1)
      current(root.right,l-1,f) #c(150,2) #c(75,1) #c(180,1)
    else:
      current(root.right,l-1,f) #(150,1,false)
      current(root.left,l-1,f) #(50,1,false)



def minv(root):
  if root is None:
    return 0
  else:
    while(root.left):
      root=root.left
  print(root.data)

def maxv(root):
  if root is None:
    return 0
  else:
    while(root.right):
      root=root.right
  print(root.data)

# level order using queue  
def level_q(root):
  if root is None:
    return 0
  q=deque([root])
  while(q):
    node=q.popleft()
    print(node.data,end=" ")
    if node.left:
      q.append(node.left)
    if node.right:
      q.append(node.right)


#zigzag level order using queue

def zigzag_q(root):
  if root is None:
    return 0
  r=[]
  q=deque([root])
  lr=True
  while(q):
    level_size=len(q)
    level_nodes=deque()
    for p in range(level_size):
      node=q.popleft()
      if lr:
          level_nodes.append(node.data)
      else:
          level_nodes.appendleft(node.data)
      if node.left:
         q.append(node.left)
      if node.right:
         q.append(node.right)
    lr=not lr
    r.append(list(level_nodes))
  return r     


def right_view(root):
  if root is None:
    return 0
  q=deque([root])
  while(q):
    n=len(q)
    for p in range(n):
      node=q.popleft()
      if(p==n-1):
        
        print(node.data,end=" ") 
      if node.left:
        q.append(node.left)
      if node.right:
        q.append(node.right)


def left_view(root):
  if root is None:
    return 0
  q=deque([root])
  while(q):
    n=len(q)
    for p in range(n):
      node=q.popleft()
      if(p==n-1):

        print(node.data,end=" ") 
      if node.right:
        q.append(node.right)
      if node.left:
        q.append(node.left)

def search(root,key):
  if root is None:
    return 0
  if root.data==key:
    return 1
  elif key<root.data:
    return search(root.left,key)
  elif key>root.data:
    return search(root.right,key)


n1=Node(27)
n1.insert(14)
n1.insert(35)
n1.insert(10)
n1.insert(19)
n1.insert(31)
n1.insert(42)
print("preorder : ")
preorder(n1)
print("\n")
print("inorder : ")
inorder(n1)
print("\n")
print("postorder : ")
postorder(n1)
print("\n")
h=height(n1)
print("height",h)
print("\n")
# level(n1)
zigzag(n1)
print("\n")
minv(n1)
print("\n")
maxv(n1)
print("\n")
level_q(n1)
print("\n")
l=zigzag_q(n1)
print(l)
right_view(n1)
print("\n")
left_view(n1)
s=search(n1,10)
print("\n")
print(s)