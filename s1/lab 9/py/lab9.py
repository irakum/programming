import re


def same_first_last(line):
    words = re.split("[ ,.]+", line)
    same = []
    count = 0
    for word in words:
        if word[0] == word[-1]:
            same.append(word)
            count += 1
    return same, count


string = input("Enter a string: ")
print("Words with the same first and last symbols: ", same_first_last(string)[0])
print("Number of these words: ", same_first_last(string)[1])
