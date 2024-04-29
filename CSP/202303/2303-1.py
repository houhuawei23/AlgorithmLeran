# 田地丈量

n, a, b = map(int, input().strip().split())

RECT0 = [(0, 0), (a, b)]


def calc_area(rect1, rect2):
    # rect1 is left most
    if rect2[0][0] < rect1[0][0]:
        tmp = rect1
        rect1 = rect2
        rect2 = tmp
    rect1_width = rect1[1][0] - rect1[0][0]
    rect1_high = rect1[1][1] - rect1[0][1]
    rect2_width = rect2[1][0] - rect2[0][0]
    rect2_high = rect2[1][1] - rect2[0][1]
    # print(rect1)
    # print(rect2)
    # if rect2 (x1,y1) in rect1
    if rect1[0][0] <= rect2[0][0] <= rect1[1][0]:  # x
        # print("1")
        if rect1[0][1] <= rect2[0][1] <= rect1[1][1]:  # 1.y1 <= 2.y1 <= 1.y2
            # print("1.1")
            if rect2[1][0] <= rect1[1][0] and rect2[1][1] <= rect1[1][1]:
                # 2.x2 <= 1.x2 and 2.y2 <= 1.y2
                # print("1.1.1")
                # rect2 in rect1
                area = rect2_width * rect2_high
            elif rect2[1][0] <= rect1[1][0] and rect2[1][1] >= rect1[1][1]:
                # 2.x2 <= 1.x2 and 2.y2 >= 1.y2
                # print("1.1.2")
                # rect2 y2 > rect1 y1
                area = rect2_width * (rect1[1][1] - rect2[0][1])
            elif rect2[1][0] >= rect1[1][0] and rect2[1][1] <= rect1[1][1]:
                # 2.x2 >= 1.x2 and 2.y2 <= 1.y2
                # print("1.1.3")
                # rect2.x2 >= rect1.x2 and rect2.y2 <= rect1.y2
                area = (rect1[1][0] - rect2[0][0]) * rect2_high
            elif rect2[1][0] >= rect1[1][0] and rect2[1][1] >= rect1[1][1]:
                # 2.x2 >= 1.x2 and 2.y2 >= 1.y2
                # print("1.1.4")
                area = (rect1[1][0] - rect2[0][0]) * (rect1[1][1] - rect2[0][1])
            else:
                print("error")
                area = 0
        elif rect2[0][1] <= rect1[0][1]:  # 2.y1 <= 1.y1
            # print("1.2")
            if rect2[1][0] <= rect1[1][0] and rect1[0][1] <= rect2[1][1] <= rect1[1][1]:
                # 2.x2 <= 1.x2 and 1.y1 <= 2.y2 <= 1.y2
                area = rect2_width * (rect2[1][1] - rect1[0][1])
            elif rect2[1][0] <= rect1[1][0] and rect1[1][1] <= rect2[1][1]:
                # 2.x2 <= 1.x2 and 1.y2 <= 2.y2
                area = rect2_width * rect1_high
            elif (
                rect2[1][0] >= rect1[1][0] and rect1[0][1] <= rect2[1][1] <= rect1[1][1]
            ):
                # 2.x2 >= 1.x2 and 1.y1 <= 2.y2 <= 1.y2
                area = (rect1[1][0] - rect2[0][0]) * (rect2[1][1] - rect1[0][1])
            elif rect2[1][0] >= rect1[1][0] and rect1[1][1] <= rect2[1][1]:
                # 2.x2 >= 1.x2 and 1.y2 <= 2.y2
                area = (rect1[1][0] - rect2[0][0]) * rect1_high
            else:
                area = 0
        else:
            area = 0
    else:
        area = 0
    return area

    # print(rect1, rect2)


res = []
for i in range(n):
    x1, y1, x2, y2 = map(int, input().strip().split())
    tmp = calc_area(RECT0, [(x1, y1), (x2, y2)])
    res.append(tmp)
# for e in res:
#     print(e)
print(sum(res))
