def main():
    numberOfDate = int(input())
    solutionOfDate = []
    nameOfMonth = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']
    while(numberOfDate != 0):
        date = input().split(' ')
        solutionOfDate.append(date[2] + "-" + str(nameOfMonth.index(date[1])) + "-"+ date[0][:-2])
        numberOfDate -= 1
    print('\n'.join(solutionOfDate))

#Activating the main function
if __name__ == "__main__": main()
