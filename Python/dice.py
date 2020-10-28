# import module
import random

while True:
    # initialition dice variale
    dice = random.randint(1, 6)
    print('You want to roll the dice?')
    # make choice for user
    print('1. Yes')
    print('2. No')

    # printing the input
    choice = int(input())
    if choice == 1:
        # print number of dice
        print('Your dice stopped at ' + str(dice))
        print('\n')
    elif choice == 2:
        break