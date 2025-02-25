import random
import time
print("WELCOME TO THE GAME STONE PAPER SCISSORS.\nTHE RULES ARE CLEAR\nSTONE DEFEATS SCISSOR\nSCISSOR DEFEATS PAPER AND\nPAPER DEFEATS STONE\nTHERE WILL BE TOTAL 10 ROUNDS WHOEVER SCORES THE MOST WILL BE THE WINNER\nDRAW MATCHES WILL NOT BE COUNTED")
time.sleep(4)
u_score = 0
c_score = 0
k = 0
d = {1:'STONE', 2:'PAPER', 3:'SCISSOR'}
while k<10:
    try:
        u_choice = int(input("ENTER YOUR CHOICE\n1 FOR STONE\n2 FOR PAPER\n3 FOR SCISSOR\n"))
    except:
        print("INVALID INPUT PLEASE TRY AGAIN")
        continue
    c_choice = random.choice([1,2,3])

    if c_choice == 1:
        if u_choice == 1:
            print(f"USERS CHOICE IS {d[1]}\nAND COMPUTER'S CHOICE IS {d[1]}")
            time.sleep(1)
            print("SO, THE MATCH IS A DRAW")
            continue
        elif u_choice == 2:
            print(f"USERS CHOICE IS {d[2]}\nAND COMPUTER'S CHOICE IS {d[1]}")
            time.sleep(1)
            print("SO, THE MATCH IS WON BY USER")
            u_score+=1
        elif u_choice == 3:
            print(f"USERS CHOICE IS {d[3]}\nAND COMPUTER'S CHOICE IS {d[1]}")
            time.sleep(1)
            print("SO, THE MATCH IS WON BY COMPUTER")
            c_score+=1

    elif c_choice == 2:
        if u_choice == 1:
            print(f"USERS CHOICE IS {d[1]}\nAND COMPUTER'S CHOICE IS {d[2]}")
            time.sleep(1)
            print("SO, THE MATCH IS WON BY COMPUTER")
            c_score+=1
        elif u_choice == 2:
            print(f"USERS CHOICE IS {d[2]}\nAND COMPUTER'S CHOICE IS {d[2]}")
            time.sleep(1)
            print("SO, THE MATCH IS A DRAW")
            continue
        elif u_choice == 3:
            print(f"USERS CHOICE IS {d[3]}\nAND COMPUTER'S CHOICE IS {d[2]}")
            time.sleep(1)
            print("SO, THE MATCH IS WON BY USER")
            u_score+=1

    elif c_choice == 3:
        if u_choice == 1:
            print(f"USERS CHOICE IS {d[1]}\nAND COMPUTER'S CHOICE IS {d[3]}")
            time.sleep(1)
            print("SO, THE MATCH IS WON BY USER")
            u_score+=1
        elif u_choice == 2:
            print(f"USERS CHOICE IS {d[2]}\nAND COMPUTER'S CHOICE IS {d[3]}")
            time.sleep(1)
            print("SO, THE MATCH IS WON BY COMPTER")
            c_score+=1
        elif u_choice == 3:
            print(f"USERS CHOICE IS {d[3]}\nAND COMPUTER'S CHOICE IS {d[3]}")
            time.sleep(1)
            print("SO, THE MATCH IS A DRAW")
            continue
    k+=1    
    print(f"ROUND {k} OVER")

print("SINCE THE 10th ROUND IS OVER ITS TIME TO DECIDE THE WINNER")   
print(f"COMPUTER'S SCORE IS {c_score}\nAND USER'S SCORE IS {u_score}")
if c_score<u_score:
    print("SO THE WINNER IS USER\nCONGRATS FOR THE WIN IT WAS A NICE PLEASURE PLAYING WITH YOU")
elif c_score>u_score:
    print("SO THE WINNER IS COMPUTER\nNICE TRY MATE IT WAS A PLEASURE PLAYING WITH YOU")
elif c_score==u_score:
    print("SINCE BOTH PLAYERS HAVE THE SAME SCORE THE MATCH IS A DRAW\nIT WAS A GOOD MATCH, HAVE A NICE DAY")
         
