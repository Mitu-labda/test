def scurry(f,n):
#scurry(sum,3)(1,2,3)-->sum[1,2,3]
  def h(k,arga_so_far):
    if k==0:
      return  f(arga_so_far)
    return lambda x: h(k-1,arga_so_far+[x])
  return h(n,[])

def factorize(n,k=2):
#factorize(12)-->2*2*3 2*6 3*4 12 >>4 
  if n==1 or n==k:
    return 1
  elif k>n:
    return 0
  elif n%k!=0:
    return factorize(n,k+1)
  return factorize(n,k+1)+factorize(n//k,k)

s=[[i] for i in range(3)]
s.append(s)
for t in list(s):
  t.extend(range(3,5))

class A:
    b='one'
    def __init_(self,a):
        f=self.a
        self.a=a[1:]
        self.b='two'
        f(a)   #调用def a
    def a(self,b):
        print([b,type(self).b])
    def __repr__(self):
        return str(self.a)
  A('four')
  B('five')

class B:
      b='three'
      def a(self,c):
          A.a(self,self.b)

f=lambda g,h:lambda p,q :h(g(q)),p)
g=f(lambda half:half//2,pow)


class Tree:
    def __init__(self, label, branches=[]):
        for branch in branches:
            assert isinstance(branch, Tree)
        self.label = label
        self.branches = branches

    def is_leaf(self):
        return not self.branches


def bigs(t):
    """Return the number of nodes in t that are larger than all their ancestors.

    >>> p = Tree(1, [Tree(4, [Tree(4), Tree(5)]), Tree(3, [Tree(0, [Tree(6)])])])
    >>> bigs(p)
    5
    >>> q = Tree(1, [Tree(4, [Tree(4), Tree(5)]), Tree(3, [Tree(0, [Tree(2)])])])
    >>> bigs(q)
    4
    """
    def f(a, x):
        if a.label > x:
            return 1 + sum([f(b, a.label) for b in a.branches])
        else:
            return sum([f(b, x) for b in a.branches])
    return f(t, t.label - 1)

def bigs(t):
    def f(x):
        def helper(a):
            if a.label > x:
                return 1 + sum([helper(b) for b in a.branches])
            else:
                return sum([helper(b) for b in a.branches])
        return helper(t)
    return f(t.label - 1)


  
def bigs_nonlocal(t):
    """Return the number of nodes in t that are larger than all their ancestors.

    >>> p = Tree(1, [Tree(4, [Tree(4), Tree(5)]), Tree(3, [Tree(0, [Tree(6)])])])
    >>> bigs_nonlocal(p)
    5
    >>> q = Tree(1, [Tree(4, [Tree(4), Tree(5)]), Tree(3, [Tree(0, [Tree(2)])])])
    >>> bigs_nonlocal(q)
    4
    """
    n = 0
    def f(a, x):
        nonlocal n
        if a.label > x:
            n += 1
        for b in a.branches:
            f(b, max(a.label, x))
    f(t, t.label - 1)
    return n


def smalls(t):
    """Return the non-leaf nodes in t that are smaller than all their descendants.

    >>> a = Tree(1, [Tree(2, [Tree(4), Tree(5)]), Tree(3, [Tree(0, [Tree(6)])])])
    >>> sorted([t.label for t in smalls(a)])
    [0, 2]
    """
    result = []
    # (a Tree t) -> (the smallest value within t)
    # side-effect: perhaps add t to result
    def process(t):
        if t.is_leaf():
            return t.label
        else:
            smallest = min([process(b) for b in t.branches])
            if t.label < smallest:
                result.append(t)
            return min(smallest, t.label)
    process(t)
    return result
