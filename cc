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
