from __future__ import print_function
import ctypes
import sys,os,random

def xiajb():
    fd = open("./test", "a+")
    fd.write("yes")
    fd.write(str(random.randint(0,9999)))
    fd.close()

def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False


if is_admin():
    # 将要运行的代码加到这里
    os.chdir("C:/autoC")
    xiajb()
    os.system("git add test")
    os.system("git commit -m yes")
    os.system("git push")
    time.sleep(5)
    #os.system("date 2020/12/22")
else:
    if sys.version_info[0] == 3:
        ctypes.windll.shell32.ShellExecuteW(
            None, "runas", sys.executable, __file__, None, 1)
    else:  # in python2.x
        ctypes.windll.shell32.ShellExecuteW(None, u"runas", unicode(
            sys.executable), unicode(__file__), None, 1)
