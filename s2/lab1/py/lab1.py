def input_text():
    print('Press Enter to go to the next line. Start new line, press Alt+1 and then Enter to end typing.'
          '\nEnter your text here:')
    end_of_text = 9786
    lines = []
    while True:
        line = input()
        if ord(line[0]) == end_of_text:
            break
        lines.append(line)
    return lines


def get_file(name, text):
    file = open(name, 'w')
    for line in text:
        file.write(line)
        file.write('\n')
    file.close()


def read_file(name):
    file = open(name, 'r')
    text = file.read()
    lines = text.splitlines()
    return lines


def changed_text(old):
    text = []
    for line in old:
        new_line = str(len(line)) + ' ' + line
        text.append(new_line)
    return text


def output(text):
    for line in text:
        print(line)


started = input_text()
get_file('Text.txt', started)
first = read_file('Text.txt')
print('Text in the first file:')
output(first)

changed = changed_text(first)
get_file('New.txt', changed)
second = read_file('New.txt')
print('Text in the second file:')
output(second)
