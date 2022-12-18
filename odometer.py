def odometer(a:int,b:int) -> int:
    odo = 0
    for value in range (a,b):
        if len(str(odo)) < 4:
            odo = (odo*10) + value
            value += 1
        return odo
        odo = 0
print(odometer(1,9))
