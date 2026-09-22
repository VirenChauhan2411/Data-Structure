void DFS(int vertex)
{
    visited[vertex] = 1;
    printf("%d",vertex);


}
struct node *save = adjlist[vertex];

while (save != NULL)

[
    int connectedVertex = save -> info;
    if(!visited[connectedVertex])
    {
        DFS(connectedVertex);
      }
]