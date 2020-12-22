from __future__ import print_function
import ctypes
import sys,os


def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False


if is_admin():
    # 将要运行的代码加到这里
    os.system("cmd")
else:
    if sys.version_info[0] == 3:
        ctypes.windll.shell32.ShellExecuteW(
            None, "runas", sys.executable, __file__, None, 1)
    else:  # in python2.x
        ctypes.windll.shell32.ShellExecuteW(None, u"runas", unicode(
            sys.executable), unicode(__file__), None, 1)
