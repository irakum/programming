import math

max_fib = 100
new_last = num_new = sec_last = last = 1

while (last + sec_last) <= max_fib:
    new_last = last + sec_last
    num_new += 1
    sec_last = last
    last = new_last

    sum_i = 0

    for i in range(1, int(math.sqrt(new_last) + 1)):
        if new_last % i == 0:
            sum_i += 1
    if sum_i == 1:
        print(new_last, " with a serial number ", num_new)
