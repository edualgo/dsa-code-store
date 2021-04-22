def dfs(V,vis,adj): # V is no of vertices and adj is adjaceny List
	if vis[V]==True:
		return
	vis[V]=True
	for i in adj[V]:
		if vis[i]==False:
			dfs(i,vis,adj)
	return 
if __name__== '__main__':
  for _ in range(int(input())):
    N,M=map(int,input().split()) # N is number of vertices and M is number of edges
    adj = [ []  for v in range(N+1) ]
    for _ in range(M): #INPUT OF EDGEs
      x,y=map(int,input().split())
      adj[x].append(y) # DIRECTED GRAPH
    vis=[False for i in range(N+1)]
    cnt=0
    for i in range(1,N+1):
    	if vis[i]==False:
    		cnt+=1
    		dfs(i,vis,adj)
    if(cnt==1):
    	print("Connected")
    else:
    	print("Not Connected")
