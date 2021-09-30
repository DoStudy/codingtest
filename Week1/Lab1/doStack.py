class doStack:
    def __init__ (self):
        self.top = []
    
    def __len__(self):
        return len(self.top)

    def __str__(self):
        return str(self.top[::1])
    
    def do_clear(self):
        self.top=[]

    def do_push(self, item):
        self.top.append(item)

    def do_pop(self):
        if not self.isEmpty():
            return self.top.pop(-1)
        else:
            print("Stack is empty")
    
    def do_peek(self):
        if not self.isEmpty():
            return self.top[-1]
        else:
            print("Stack is empty")

    def isEmpty(self):
        return len(self.top)==0