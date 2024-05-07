#Ethan Hernandez
#Lab 2

from random import randint, seed


def getNum(counter, x, y = 0) : 
    """
    Used to receive user input throughout the game.

    Parameters : 
        counter : used to determine the correct way to prompt the user(i.e. board size, row, or column)
        x : used as a parameter for range() to verify user input
        y : used as a parameter for range() to verify user input

    Returns : 
        size : board size
        r : user's guess for the row
        c : user's guess for the column
    """
    if counter < 1 :
        size = int(input("Enter size of board: "))
        while size not in range(x, y + 1) : 
            print("Size must be 2 - 4")
            size = int(input("Enter size of board: "))
        return size
    elif counter == 1 :
        r = int(input("Enter a row: "))
        while r not in range(1, x + 1) :
            print("Row must be between 1 -", x)
            r = int(input("Enter a row: "))
        return r
    else :
        c = int(input("Enter a column: "))
        while c not in range(1, x + 1) :
            print("Column must be between 1 -", x)
            c = int(input("Enter a column: "))
        return c


def printBoard(size, r = 1, c = 1, correctR = 0, correctC = 0) : 
    """
    Displays the appropriately sized board to the user.

    Parameters : 
        size : board size
        r : row that the user has guessed
        c : column that the user has guessed
        correctR : row where the ship is hidden
        correctC : column where the ship is hidden
    
    Returns : 
        True : if the user has correctly guessed the ship location
        False : if the user has failed to guess the ship's location correctly
    """
    print(" ", end = " ")
    for i in range(1, size + 1) : 
        print(" ", i, end = " ")
    print()
    print(" ", end = " ")
    print("-" * (4 * size))
    for i in range(1, size + 1) :
        print(i, end = " |")
        for j in range(1, size + 1) : 
            if i == r == correctR and j == c == correctC :
                print(" " + "X" + " ", end = "|")
            else : 
                print(" " * 3, end = "|")
        print()
        print(" ", end = " ")
        print("-" * (4 * size))
    if r == correctR and c == correctC : 
        return True
    else : 
        return False
    

def hideShip(size) : 
    """
    Hides the ship randomly on the board.

    Parameters :
        x : board size

    Returns : 
        r : randomly generated row for the ship
        c : randomly generated column for the ship
    """

    r = randint(1, size)
    c = randint(1, size)
    print(r, c)
    return (r, c)


def play() : 
    """
    Called once per game; keeps track of any needed variables and counters, and calls all of the above functions when appropriate for the game to work correctly.

    Parameters : 
        None
    
    Returns : 
        None
    """
    MIN = 2
    MAX = 4
    getNumCounter = 0
    size = getNum(getNumCounter, MIN, MAX)
    getNumCounter += 1
    correct = printBoard(size)
    correctR, correctC = hideShip(size)
    guessCount = 0
    while not correct :
        r = getNum(getNumCounter, size)
        getNumCounter += 1
        c = getNum(getNumCounter, size)
        getNumCounter = 1
        guessCount += 1
        correct = printBoard(size, r, c, correctR, correctC)
    print()
    print("You got it in", guessCount, "tries!")
    

def main() : 
    """
    Seeds random and asks the user if they want to play again each time a game is completed, if they answer no then ends the program.

    Parameters : 
        None
    
    Returns :
        None
    """
    seed()
    play()
    playAgain = (input("Continue? y/n: "))
    while playAgain.lower() == "y" : 
        play()
        playAgain = (input("Continue? y/n: "))
    exit()
        
if __name__=="__main__":
    main()