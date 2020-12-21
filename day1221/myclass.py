class mytest:
    age = 0
    name = ""
    __count = 10
    def __init__(self, age, name, count):
        self.age = age
        self.name = name
        self.__count=count
    def get_count(self):
        return self.__count
        

    
a = mytest(100, "ddddd", 100)
print(a.age,a.name,a.get_count())
     