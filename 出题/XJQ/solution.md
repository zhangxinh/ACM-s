每章的前置章节相当于一条有向边从前置章节指向这一章，可以构成一张有向图。

发现每章都必须在前置章节读懂完后才能读懂，该问题就可以转化为 DAG 上$dp$。

转移方程为：

$$
dp_v = 
    \begin{cases}
        max(dp_v, dp_u + 1), v < u \\\\
        max(dp_v, dp_u), v > u
    \end{cases}
    u \rightarrow v
$$