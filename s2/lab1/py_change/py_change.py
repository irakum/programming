import func


def main():
    func.get_first('Text.txt')
    print('Text in the first file:')
    func.output('Text.txt')

    func.get_second('New.txt', 'Text.txt')
    print('Text in the second file:')
    func.output('New.txt')


if __name__ == "__main__":
    main()