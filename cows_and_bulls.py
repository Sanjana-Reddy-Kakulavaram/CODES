import random

def cowBull(num):
    val_guess = str(input("enter your number: "))
    cow = 0
    bullCow = 0  
    for i in range(0, 4):
        if num[i] == val_guess[i]:
            cow += 1
    for i in num:
        if i in val_guess:
            bullCow += 1
    bull = bullCow - cow
    print("{} cow and {} bulls".format(cow,bull))
    return cow


def game():
    num = str(random.randrange(1000, 9999))
    cow = 0
    count = 0
    while cow != 4:
        count += 1
        cow = cowBull(num)
    if cow == 4:
        print(count)

 

print(game())

