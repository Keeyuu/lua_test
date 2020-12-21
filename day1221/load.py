import pickle

#使用pickle模块从文件中重构python对象
pkl_file = open("./test", "rb")

data1 = pickle.load(pkl_file)
print(data1)

data2 = pickle.load(pkl_file)
print(data2)

pkl_file.close()
