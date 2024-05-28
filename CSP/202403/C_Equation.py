"""
1. be careful for isZero()
2. unit test

need try cpp
"""

n = int(input().strip())


def parse_elenum(elenum: str):
    ele = ""
    numstr = ""
    next = False
    for e in elenum:
        if not e.isnumeric():
            if next:
                break
            ele += e
        else:
            numstr += e
            next = True
    assert numstr.isnumeric()
    num = int(numstr)
    length = len(ele + numstr)
    # print(ele, numstr, num)
    return ele, num, length


# parse_elenum("al25ssf2")
# exit()


def parse_unit(unit: str):
    """
    unit: n2o4
    return: {"n": 2, "o": 4}
    """
    # print(f"unit: {unit}")
    cntMap = dict()  # ele -> num
    ele = ""
    i = 0
    while i < len(unit):
        ele, num, length = parse_elenum(unit[i:])
        i = i + length
        cntMap[ele] = num
    return cntMap


# parse_unit("al25ssf2")
# exit()


def isZero(x, epsilon = 1e-4):
    return True if abs(x) < epsilon else False

def cal_zhi(matrix: list) -> int:
    """
    return zhi
    """
    rowCnt = len(matrix)
    colCnt = len(matrix[0])

    # for col in colCnt:
    row = 0
    col = 0
    while col < colCnt:
        # check all zero
        allZero = True
        # for row in rowCnt:
        for r in range(row, rowCnt):
            if not isZero(matrix[r][col]):  # != 0
                allZero = False
                break
        if allZero:
            col += 1
            continue
        # not all Zero
        # check [row][col]
        if isZero(matrix[row][col]):
            for nrow in range(row + 1, rowCnt):
                if not isZero(matrix[nrow][col]):
                    # exchange
                    matrix[row], matrix[nrow] = matrix[nrow], matrix[row]

        # all next row delete cur row times a
        for nrow in range(row + 1, rowCnt):
            if isZero(matrix[nrow][col]):
                continue
            times = matrix[nrow][col] / matrix[row][col]
            matrix[nrow][col] = 0
            for c in range(col + 1, colCnt):
                matrix[nrow][c] -= times * matrix[row][c]
        col += 1
        row += 1

    # print("matrx after gas xiaoyuan")

    # for line in matrix:
    #     print(line)

    zhi = 0
    for r in range(rowCnt):
        allZero = True
        for c in range(colCnt):
            if not isZero(matrix[r][c]):
                allZero = False
        if not allZero:
            zhi += 1

    # print(f"zhi: {zhi}")
    return zhi


def check(eq: list):
    """
    eq = ["c1o1", "c1o2", "o2"]
    """
    # print(eq)
    unitCnt = len(eq)

    eleUnitsMap = dict()
    for unit in eq:
        cntMap = parse_unit(unit)
        for ele, num in cntMap.items():
            if ele not in eleUnitsMap.keys():
                eleUnitsMap[ele] = dict()
            eleUnitsMap[ele][unit] = num

    # for ele, mp in eleUnitsMap.items():
    #     print(ele)
    #     print(mp)

    eleCnt = len(eleUnitsMap.keys())
    matrix = [[0 for _ in range(unitCnt)] for _ in range(eleCnt)]

    i = 0
    for ele, mp in eleUnitsMap.items():
        j = 0
        for unit in eq:
            if unit in mp:
                matrix[i][j] = mp[unit]
            j += 1
        i += 1
    # print("matrx")
    # for line in matrix:
    #     print(line)
    zhi = cal_zhi(matrix)
    if zhi < unitCnt:
        return True
    return False


# check("o2 o3".split())
# check("c1o1 c1o2 o2".split())
# check("n2o4 n1o2".split())
# check("cu1 h1n1o3 cu1n2o6 h2o1".split())
# check("al2s3o12 n1h5o1 al1o3h3 n2h8s1o4".split())
# check("c1o1 c1o2 o2 h2o1".split()) # Y
# exit()
equations = []


for i in range(n):
    line = input().split()
    m = int(line[0])
    eq = line[1:]
    equations.append(eq)

for eq in equations:
    if check(eq):
        print("Y")
    else:
        print("N")
