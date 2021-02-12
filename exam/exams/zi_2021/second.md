```py
def dfs(i):
    obideni[i] = True
    susjedi = getSusjedi()

    for susjed in susjedi:
        if susjed[i].noObiden:
            dfs(susjed[i])
```
