def create_file(name):
    ch = input('Would you like to rewrite text in file (Y/N)? ').lower()
    while ch != 'y' and ch != 'n':
        ch = input('Wrong input. Enter "Y" or "N": ')
    if ch == 'y':
        file = open(name, 'wb')
    else:
        file = open(name, 'ab')
    n = get_amount()
    for i in range(n):
        person = get_name() + get_day() + get_month() + get_year() + get_number() + get_gender()
        year = int(person[27:31])  # cutting out year
        while year < 1962 or year > 2002:
            print('Age of this person is out of range. Try again.')
            person = get_name() + get_day() + get_month() + get_year() + get_number() + get_gender()
            year = int(person[27:31])
        file.write(bytes(person.encode()))
        print('Recorded')
    file.close()


def get_sorted(over, under, name):
    file = open(name, 'rb')
    ov_file = open(over, 'wb')
    un_file = open(under, 'wb')
    text = file.read().decode()
    lines = text.splitlines()
    for person in lines:
        year = int(person[27:31])
        if year < 1982:
            ov_file.write(person.encode())
        else:
            un_file.write(person.encode())
    file.close()
    ov_file.close()
    un_file.close()


def get_amount():
    num = input('Enter number of workers to add: ')
    while not num.isdigit():
        num = input('Enter a positive integer: ')
    return int(num)


def get_name():
    name = input('Full name (up to 20 synbols): ')
    while len(name) > 20:
        name = input('Too long. Try again: ')
    name = ' ' * (20 - len(name)) + name + ' '
    return name


def get_number():
    number = input('Employee number: ')
    while not number.isdigit() or len(number) != 8:
        number = input('Wrong input. Enter 8 digits: ')
    return number + ' '


def get_gender():
    gen = input('Gender (M/F): ').lower()
    while gen != 'm' and gen != 'f':
        gen = input('Wrong input. Enter letter M for male or F for female: ')
    if gen == 'm':
        return '  male\n'
    else:
        return 'female\n'


def get_day():
    day = input('Day of birth: ')
    while not day.isdigit() or int(day) > 31:
        day = input('Wrong input. Enter a number from 1 to 31: ')
    day = '0' * (2 - len(day)) + day + '.'
    return day


def get_month():
    month = input('Month of birth (number): ')
    while not month.isdigit() or int(month) > 12:
        month = input('Wrong input. Enter a number from 1 to 12: ')
    month = '0' * (2 - len(month)) + month + '.'
    return month


def get_year():
    year = input('Year of birth: ')
    while not year.isdigit() or int(year) < 1900 or int(year) > 2022:
        year = input('Wrong input. Try again: ')
    return year + ' '


def output_file(name):
    file = open(name, 'rb')
    print(file.read().decode())
    file.close()
