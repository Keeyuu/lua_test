

class list_:
    a = {}
    def __getitem__(self, n):
        return self.a[n]
    def __setitem__(self, n,b1):
        self.a[n] = b1
    def __len__(self):
        return 100

test = list_()

test[1] = 1
print(len(test))
print(test[1])

