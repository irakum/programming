import pickle


def create_file(name):
    ch = input('Would you like to rewrite text in file (Y/N)? ').lower()
    while ch != 'y' and ch != 'n':
        ch = input('Wrong input. Enter "Y" or "N": ')
    if ch == 'y':
        file = open(name, 'wb')
    else:
        file = open(name, 'ab')
    n = get_amount()
    people = []
    for i in range(n):
        person = {
            "name": get_name(),
            "day": get_day(),
            "month": get_month(),
            "year": get_year(),
            "number": get_number(),
            "gender": get_gender()
        }
        while person["year"] < 1962 or person["year"] > 2002:
            print('Age of this person is out of range. Try again.')
            person = {
                "name": get_name(),
                "day": get_day(),
                "month": get_month(),
                "year": get_year(),
                "number": get_number(),
                "gender": get_gender()
            }
        people.append(person)
        print('Recorded')
    pickle.dump(people, file)
    file.close()


def get_sorted(over, under, name):
    file = open(name, 'rb')
    ov_file = open(over, 'wb')
    un_file = open(under, 'wb')
    people = pickle.load(file)
    un = []
    ov = []
    for person in people:
        if person["year"] < 1982:
            ov.append(person)
        else:
            un.append(person)
    pickle.dump(un, un_file)
    pickle.dump(ov, ov_file)
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
    name = ' ' * (20 - len(name)) + name
    return name


def get_number():
    number = input('Employee number: ')
    while not number.isdigit() or len(number) != 8:
        number = input('Wrong input. Enter 8 digits: ')
    return number


def get_gender():
    gen = input('Gender (M/F): ').lower()
    while gen != 'm' and gen != 'f':
        gen = input('Wrong input. Enter letter M for male or F for female: ')
    if gen == 'm':
        return '  male'
    else:
        return 'female'


def get_day():
    day = input('Day of birth: ')
    while not day.isdigit() or int(day) > 31:
        day = input('Wrong input. Enter a number from 1 to 31: ')
    day = '0' * (2 - len(day)) + day
    return day


def get_month():
    month = input('Month of birth (number): ')
    while not month.isdigit() or int(month) > 12:
        month = input('Wrong input. Enter a number from 1 to 12: ')
    month = '0' * (2 - len(month)) + month
    return month


def get_year():
    year = input('Year of birth: ')
    while not year.isdigit() or int(year) < 1900 or int(year) > 2022:
        year = input('Wrong input. Try again: ')
    return int(year)


def output_file(name):
    file = open(name, 'rb')
    people = pickle.load(file)
    for person in people:
        print(person["name"] + ' ' + person["day"] + '.' + person["month"] + '.' + str(person["year"]) + ' '
              + person["number"] + ' ' + person["gender"])
    file.close()
