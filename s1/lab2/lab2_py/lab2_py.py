#is it possible to fit the first rectangle in the second one

a = float(input("Enter the first side of the first rectangle: "))
if a <= 0:
    print("Invalid value, try again")
    exit(0)
b = float(input("Enter the second side of the first rectangle: "))
if b <= 0:
    print("Invalid value, try again")
    exit(0)
c = float(input("Enter the first side of the second rectangle: "))
if c <= 0:
    print("Invalid value, try again")
    exit(0)
d = float(input("Enter the second side of the second rectangle: "))
if d <= 0:
    print("Invalid value, try again")
    exit(0)

max_first = max(a, b)
max_second = max(c, d)
min_first = min(a, b)
min_second = min(c, d)

if max_second > max_first and min_second > min_first:
    print("It is possible to fit the first rectangle in the second one.")
else:
    print("It is impossible to fit the first rectangle in the second one.")