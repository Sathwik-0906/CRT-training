from collections import deque
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

def level_q(root):
   if root is None:
      return 0
   q=deque([root])
   while(q):
      node=q.popleft()
      print(node.data,end=" ")
      if node.left:
         q.append(node.left)
      if node.left:
         q.append(node.right)   


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

print("\n")
level_q(n1)