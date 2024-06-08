memset 是对 byte 赋值, 不能用来初始化数组为任意值, 常用的方法:
- `memset(a, 127, sizeof(a))`: 初始化为非常大值(+inf) or `0x3f`
- `memset(a, 128, sizeof(a))`: 初始化为非常小值(-inf)
- `memset(a, 0, sizeof(a))`: 初始化为0
- `memset(a, -1, sizeof(a))`: 初始化为-1

[memset 0x3f/127](https://blog.csdn.net/lyj2014211626/article/details/65481630)

们在很多程序中都会看到memset(a,127,sizeof(a));这样的代码，127是什么特别的数字呢？通过基础的进制转换可以得知127的二进制表示是01111111，那么在dp数组里放的内容就是“01111111 01111111 01111111 01111111”，（10进制的2139062143），这样就实现了将数组里的全部元素初始化为一个很大的数的目的了，在最短路径问题以及其他很多算法中都是需要用到的。值得注意的是，int类型的范围为2^31-1，大约是2147483647的样子（如果我没有记错的话），所以初始化int类型的数组也可以使用127这个数值。

[shortes path](https://blog.csdn.net/m0_50564748/article/details/123143604?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165197488516782184674179%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=165197488516782184674179&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-1-123143604-null-null.nonecase&utm_term=dijkstra&spm=1018.2226.3001.4450)