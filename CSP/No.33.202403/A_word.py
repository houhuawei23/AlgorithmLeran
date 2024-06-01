"""
词频统计

python 字符串操作

在学习了文本处理后,小P对英语书中的n篇文章进行了初步整理。
具体来说,小P将所有的英文单词都转化为了整数编号。
假设这n篇文章中共出现了m个不同的单词,则把它们从1到m进行编号。
这样,每篇文章就简化为了一个整数序列,其中每个数都在1 到 m 范围内。
现给出小P处理后的  篇文章,对于每个单词(1≤ i ≤ m),试统计:
1.单词出现在了多少篇文章中？
2.单词在全部文章中总共出现了几次？


样例输入
4 3
5 1 2 3 2 1
1 1
3 2 2 2
2 3 2
样例输出
2 3
3 6
2 2

"""

n, m = map(int, input().strip().split())
eassys = []

eassy_cnts = [0 for _ in range(m + 1)]

word_cnts = [0 for _ in range(m + 1)]
for i in range(n):
    line = list(map(int, input().strip().split()))[1:]
    for w in line:
        word_cnts[w] += 1
    for w in range(1, m + 1):
        if w in line:
            eassy_cnts[w] += 1
    eassys.append(line)
# for i in range(m):
#     word_cnts[i] = i

# print(eassys)
# print(eassy_cnts)
# print(word_cnts)

for i in range(1, m + 1):
    print(eassy_cnts[i], word_cnts[i])
