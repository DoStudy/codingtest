class doQueue:
    def __init__(self, MAX_QSIZE):
        self.front = 0
        self.rear = 0
        self.MAX_QSIZE = MAX_QSIZE
        self.items = [None] * self.MAX_QSIZE

    def isEmpty(self):
        return self.front == self.rear

    def isFull(self):
        return self.front == (self.rear+1)%self.MAX_QSIZE

    def do_clear(self):
        self.front = self.rear
    
    def do_enqueue(self, item):
        if not self.isFull():
            self.rear = (self.rear + 1) % self.MAX_QSIZE
            self.items[self.rear] = item
    
    def do_dequeue(self):
        if not self.isEmpty():
            self.front = (self.front+1) % self.MAX_QSIZE
            return self.items[self.front]


    def do_peek(self):
        if not self.isEmpty():
            return self.items[(self.front+1)%self.MAX_QSIZE]
    
    def do_print(self):
        out = []
        if self.front < self.rear:
            out = self.items[self.front+1:self.rear+1]
        else:
            out = self.items[self.front+1:self.MAX_QSIZE] + self.items[0:self.rear+1]

        print("[front=%s, rear=%d] ==> \n\t"%(self.front, self.rear), out)

    def __len__(self):
        return (self.rear - self.front + self.MAX_QSIZE) % self.MAX_QSIZE