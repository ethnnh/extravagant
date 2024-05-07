"""
Ethan Hernandez
Lab 1
"""

MAX = 40

userName = (str(input("Enter your name: ")))
userNumClasses = (int(input("Enter the number of programming classes you've taken: ")))
userGoal = (str(input("Enter the goal you have for this class: ")))

startSpace = ((MAX - (len(userName) + 2)) // 2)
endSpace = (MAX - (len(userName) + startSpace + 2))

print()
print("*" * MAX)
print("*" + " " * (MAX - 2) + "*")
print("*" + " " * startSpace + userName.title() + " " * endSpace + "*")
print("*" + " " * (MAX - 2) + "*")
print("*" * MAX)

print("You've taken", userNumClasses, "programming classes")
print("Your goal for this class is:")
print(userGoal.upper())

"""
****************************************
*                                      *
*           Ethan Hernandez            *
*                                      *
****************************************
You've taken 1 programming classes
Your goal for this class is:
TO LEARN PYTHON FOR USE IN PERSONAL PROJECTS OR INTERESTS, AS WELL AS TO JUST EXPAND MY PROGRAMMING KNOWLEDGE IN GENERAL
"""