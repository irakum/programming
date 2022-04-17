def input_text():
    print('Press Enter to go to the next line. Start new line, press Ctrl+X and then Enter to end typing.'
          '\nEnter your text here:')
    end_of_text = 24
    lines = []
    line = ' '
    while ord(line[0]) != end_of_text:
        line = input()
        lines.append(line)
        if line == "":
            line = " "
    return lines[:-1]


def get_first(name):
    ch = input('Would you like to rewrite text in file (Y/N)? ').lower()
    while ch != 'y' and ch != 'n':
        ch = input('Wrong input. Enter "Y" or "N": ')
    if ch == 'y':
        file = open(name, 'w')
    else:
        file = open(name, 'a')
        file.write('\n')
    text = input_text()
    for line in text[:-1]:
        file.write(line + '\n')
    file.write(text[-1])
    file.close()


def get_second(second, first):
    first_file = open(first, 'r')
    text = first_file.read()
    first_file.close()
    sec_text = changed_text(text)
    second_file = open(second, 'w')
    for line in sec_text[:-1]:
        second_file.write(line + '\n')
    second_file.write(sec_text[-1])
    second_file.close()


def output(name):
    file = open(name, 'r')
    text = file.read()
    print(text);
    file.close()


def changed_text(old_text):
    old = old_text.splitlines()
    text = []
    for line in old:
        new_line = str(len(line)) + ' ' + line
        text.append(new_line)
    return text
