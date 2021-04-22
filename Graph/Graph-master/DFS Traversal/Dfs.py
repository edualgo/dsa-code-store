def dfs(V , vis , adj,store): # V is no of vertices and adj is adjaceny List
	if vis[V]==True:
		return
	store.append(V)
	vis[V]=True
	for i in adj[V]:
		if vis[i]==False:
			dfs(i,vis,adj,store)
if __name__== '__main__':
  for _ in range(int(input())):
    N,M=map(int,input().split()) # N is number of vertices and M is number of edges
    adj = [ []  for v in range(N+1) ]
    for _ in range(M): #INPUT OF EDGEs
      x,y=map(int,input().split())
      adj[x].append(y) # DIRECTED GRAPH
    vis=[False for i in range(N+1)]
    store=[]
    for i in range(1,N+1):
    	if vis[i]==False:
    		dfs(i,vis,adj,store)
    print(*store)
    
