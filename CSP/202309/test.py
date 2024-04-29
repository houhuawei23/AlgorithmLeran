def cal_beta(q):
    xid = q[0]
    x = q[xid]
    xstr = f"x{xid}"
    stack = [] # (a, b)
    # ax^b 为一项
    a = 1
    b = 0
    for e in f:
        if e == "*":
            # 如果是 *
            term2 = stack.pop()
            term1 = stack.pop()
            stack.append((term1[0] * term2[0], term1[1] + term2[1]))
            continue
        elif e in ["-", "+"]:
            # 前面的项可以计算出来了
            pass

        # 计算一项过程中
        if e == xstr:
            # 如果是变量 xstr
            stack.append((1, 1))
        elif e[0] == 'x':
            # 如果是其他变量 x56
            xj = q[int(e[1:])]
            stack.append((xj, 0))
        else: # 是常数
            stack.append((int(e), 0))
def cal(q):
    xid = q[0]
    x = q[xid]
    xstr = f"x{xid}"
    stack = []
    # ax^b 为一项
    a = 1
    b = 0
    for e in f:
        if e in ["-", "+"]:
            # 前面的项可以计算出来了
            
            term = a * b * x ** (b-1)
            if not stack: # 栈空
                stack.append(term)
            else:
                old_term = stack.pop()
                stack.append(old_term)
            # 重新计算一项
            a = 1
            b = 0
            continue
        elif e == "*":
            # 如果是 *
            continue
        # 计算一项过程中
        if e == xstr:
            # 如果是变量 xstr
            b += 1
        elif e[0] == 'x':
            # 如果是其他变量 x56
            xj = q[int(e[1:])]
            a += xj
        else: # 是常数
            a += int(e)

        # if 