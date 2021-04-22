def dfs(V , vis , adj): # V is no of vertices and adj is adjaceny List
	if vis[V]==True:
		return
	vis[V]=True
	for i in adj[V]:
		if vis[i]==False:
			dfs(i,vis,adj)
if __name__== '__main__':
  for _ in range(int(input())):
    N,M=map(int,input().split()) # N is number of vertices and M is number of edges
    adj = [ []  for v in range(N+1) ]
    for _ in range(M): #INPUT OF EDGEs
      x,y=map(int,input().split())
      adj[x].append(y) # DIRECTED GRAPH
    vis=[False for i in range(N+1)]
    start,end=map(int,intput().split())
    dfs(start,vis,adj)
    if(vis[end]==True):
    	print("Path Possible")
    else:
    	print("Path Not Possible")
