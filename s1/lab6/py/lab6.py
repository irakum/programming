import math


def proste(number):
    if number <= 1:
        return False

    count = 0
    for i in range(1, int(math.sqrt(number)) + 1):
        if number % i == 0:
            count += 1

    if count == 1:
        return True
    else:
        return False


def twins(number):
    if proste(number) and proste(number + 2):
        print(number, " and ", (number+2))


n = int(input("Enter your number: "))
while n < 1:
    n = int(input("Wrong value. Enter a natural number: "))

for num in range(n, 2*n - 1):
    twins(num)
