def dfs(graph, visited, node):
    if node not in visited:
        print(node, end = " ")
        visited.add(node)
    for nbr in graph[node]:
        if nbr not in visited:
            dfs(graph, visited, nbr)


graph ={
    1:[2,3], 2:[1,4,5], 3:[7], 4:[2,5,6], 5:[4,2], 6:[4], 7:[3]
}
visited = set()
dfs(graph, visited, 1)
