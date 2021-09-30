def dfs(graph, start=0):
    n = len(graph)

    dp = [0 for x in range(n)]
    visited = [False for x in range(n)]

    stack = [start]
    while stack:
        start = stack[-1]

        if not visited[start]:
            visited[start] = True
            for child in graph[start]:
                if not visited[child]:
                    stack.append(child)

    return visited, dp
