import genericpath


def bfs(graph, node):
    queue = []
    visited = set()
    queue.append(node)
    visited.add(node)
    while queue:
        n = queue.pop(0)
        print(n, end=" ")
        for nbr in graph[n]:
            if nbr not in visited:
                queue.append(nbr)
                visited.add(nbr)

graph ={
    1:[2,3], 2:[1,4,5], 3:[7], 4:[2,5,6], 5:[4,2], 6:[4], 7:[3]
}
bfs(graph,1)

