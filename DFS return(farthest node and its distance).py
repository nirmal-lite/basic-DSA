def dfs(v, edge,visited):#dfs to return last node node and its distance
                    if v not in visited:
                            visited.add(v)
                            mx_l = 0
                            mx_v = v
                            for i in edge[v]:
                                    if i not in visited:
                                            l, vv = dfs(i, edge,visited)
                                            if l + 1 > mx_l: 
                                                    mx_l = l + 1
                                                    mx_v = vv
                            return (mx_l, mx_v)
                    # visited =set()
                    return (0, v)