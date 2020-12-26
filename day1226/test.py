def test(n, p1, p2, p3):
    if n == 1:
        print("盘子:[%d]从%d号柱子移动到了%d号柱子", n, p1, p3)
    else:
        test(n-1,)