class collatz:
    def __init__(self,num):
        self.start = num
        self.current = self.start
        self.seq = []

    def collatz_seq(self):
        while self.current > 1:
            self.seq.append(self.current)
            if self.current % 2 == 0:
                self.current =  self.current // 2
            else:
                self.current = (self.current * 3) + 1
        self.seq.append(1)
        return self.seq

c = collatz(7)
print(c.collatz_seq())
