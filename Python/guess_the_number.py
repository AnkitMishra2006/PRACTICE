import time
import random
chances = 10
number = random.randrange(1,51)

print('''WELCOME TO THE GAME "THE MAGIC NUMBER".\nSO THE GAME IS THAT YOU HAVE TO GUESS THE MAGIC NUMBER YOU WILL HAVE TOTAL OF 10 CHANCES AND IF YOU CAN'T GUESS IT IN THOSE 10 CHANCES THEN YOU WILL LOST.\nHINT: THE MAGIC NUMBER IS BETWEEN 1 AND 50\nSO LET'S START THE GAME NOW''')
time.sleep(5)
k = 0
while True:
    try:
        guess = int(input("ENTER YOUR GUESS(1-50):\n"))
        if guess in range(1,51):
            k+=1
            pass
        else:
            print("ENTER A NUMBER BETWEEN 1 AND 50\n PLEASE TRY AGAIN")
            continue
    except:
        print("INVALID INPUT PLEASE TRY AGAIN")
        continue    
    if guess==number:
        print("CONGRATS YOU WON!!")
        print(f"THE CORRECT ANSWER WAS {number}")
        break
    elif 0<number-guess<=3:
        print("WRONG!! BUT CLOSE THE MAGIC NUMBER IS LITTLE GREATER")
    elif -3<=number-guess<0:
        print("WRONG!! BUT CLOSE THE MAGIC NUMBER IS LITTLE SMALLER")
    elif 0<number-guess<=9:
        print("WRONG!! THE MAGIC NUMBER IS GREATER")
    elif -9<=number-guess<0:
        print("WRONG!! THE MAGIC NUMBER IS SMALLER")
    elif 0<number-guess<=25:
        print("WRONG!! THE MAGIC NUMBER IS FAR GREATER")
    elif -25<=number-guess<0:
        print("WRONG!! THE MAGIC NUMBER IS FAR SMALLER")
    else:
        print("SORRY, SOME UNEXPECTED ERROR OCCURED PLEASE COME LATER")
        break
    if (chances-k)==0:
        print("OOPs!! ALL CHANCES ARE GONE YOU LOST")
        print("THE RIGHT ANSWER WAS", number)
        break
    else:    
        print(f"YOU HAVE {chances-k} CHANCES LEFT")