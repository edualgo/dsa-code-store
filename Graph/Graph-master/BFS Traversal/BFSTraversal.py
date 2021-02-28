import queue
def bfs(V, adj): # V is no of vertices and adj is adjaceny List
    Q = queue.Queue() #Queue for Breadth First Search is needed 
    vis=[False for i in range(V+1)] # initializing all vertices by False
    L=[]
    Q.put(0) # you can start with Any Node of your choice for BFS , Assuming That is has one connected component in Graph we push only one Node -> Vertex 0
    vis[0]=True
    while Q.empty()==False:   # COMPLETE LOGIC FOR PERFORMING BFS
        curr=Q.get()
        L.append(curr)
        for it in adj[curr]:
            if vis[it]==False:
                Q.put(it)
                vis[it]=True
    return L
if __name__== '__main__':
  for _ in range(int( input() ) ):
    N,M=map(int,input().split()) # N is number of vertices and M is number of edges
    adj = [[] for v in range(N)]
    for _ in range(M): #INPUT OF EDGEs
      x,y=map(int,input().split())
      adj[x].append(y) # DIRECTED GRAPH
    BFS=bfs(N,adj)
    for i in BFS:
      print(i,end=" ")
    print("\n")
      
