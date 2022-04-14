import func


def main():
    func.create_file('All.txt')
    print('List of all workers:')
    func.output_file('All.txt')
    func.get_sorted('Over.txt', 'Under.txt', 'All.txt')
    print('List of workers over 40:')
    func.output_file('Over.txt')
    print('List of workers under 40:')
    func.output_file('Under.txt')


if __name__ == '__main__':
    main()
