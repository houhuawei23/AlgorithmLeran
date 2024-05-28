


def solve1():
    n, a, b = map(int, input().strip().split())

    rect0 = [0, 0, a, b]

    # areaList = []
    areaSum = 0


    def calc_insertion_area(rect1, rect2):
        #  0  1  2  3
        # x1 y1 x2 y2
        """
                    x2,y2
        x1,y1
        """
        right = min(rect1[2], rect2[2]) # x2
        left = max(rect1[0], rect2[0]) # x1
        up = min(rect1[3], rect2[3])# y2
        down = max(rect1[1], rect2[1])# y1
        if not (right > left and up > down):
            # print("not insertion!")
            return 0
        # insertion
        area = (up - down) * (right - left)
        assert area >= 0
        # print(f"insertion area: {area}")
        return area


    # calc_insertion_area([1, 0, 4, 2], [3, 3, 5, 5])

    for i in range(n):
        rect = list(map(int, input().strip().split()))
        areaSum += calc_insertion_area(rect0, rect)

    print(areaSum)

class Rectangle:
    def __init__(self, x1, y1, x2, y2) -> None:
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
    
    def insertion_area(self, rhs):
        right = min(self.x2, rhs.x2)
        left = max(self.x1, rhs.x1)
        up = min(self.y2, rhs.y2)
        down = max(self.y1, rhs.y1)
        if not (right > left and up > down):
            return 0
        # insertion
        area = (up - down) * (right - left)
        assert area >= 0
        return area

def solve2():
    areaSum = 0
    n, a, b = map(int, input().strip().split())

    rect0 = Rectangle(0, 0, a, b)

    for i in range(n):
        line = list(map(int, input().strip().split()))
        rect = Rectangle(*line)
        areaSum += rect0.insertion_area(rect)
    print(areaSum)
        


# solve1()
solve2()