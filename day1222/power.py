from __future__ import print_function
import ctypes
import sys
import os
import random

# 每日提交范围
day_min = 5
day_max = 23
# 月份开始天数和结束天数
m_min = 25
m_max = 31
# 月份
m_m = 11


def xiajb():
    fd = open("./test", "a+")
    fd.write("yes")
    fd.write(str(random.randint(0, 9999)))
    fd.close()


def shua():
    xiajb()
    os.system("git add test")
    os.system("git commit -m yes")
    #os.system("git push")


def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False


def test(i):
    # temp_str = "date 2019/12/" + str(i)
    # os.system(temp_str)
    # for index in range(day_min, random.randint(day_min, day_max)):
    #     temp_time = "time "+str(random.randint(1, 23)) + \
    #         ":"+str(random.randint(1, 59))
    #     os.system(temp_time)
        shua()


if is_admin():
    # 将要运行的代码加到这里
    os.chdir("C:/autoC")
    for i in range(m_min, m_max):
        fd = open("./log.txt", "w")
        fd.write(str(i)+"\n")
        test(i)
        fd.close
    os.system("git push")
else:
    if sys.version_info[0] == 3:
        ctypes.windll.shell32.ShellExecuteW(
            None, "runas", sys.executable, __file__, None, 1)
    else:  # in python2.x
        ctypes.windll.shell32.ShellExecuteW(None, u"runas", unicode(
            sys.executable), unicode(__file__), None, 1)
