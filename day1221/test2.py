import pickle,os
list_ = [1, 15, 4, 55, 89, 51, 54, 15, 0]
list_2 =["sadadasd","Sdaadada"]
out_ = open('./test', 'wb')

pickle.dump(list_, out_)
pickle.dump(list_2, out_ ,-1)
out_.close()