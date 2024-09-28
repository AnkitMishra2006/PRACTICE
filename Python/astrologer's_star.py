while True:
    try:
        n = int(input("ENTER THE NUMBER:\n"))
        d = int(input("ENTER 1(TRUE) OR 0(FALSE):\n"))
        if d == 1 or 0:
            pass
        else:
            print("PLEASE ENTER 1 OR 0")
            continue    
    except:
        print("INVALID INPUT TRY AGAIN ")
        continue

    for i in range(1,n+1):
        if d == 1:
            print('*'*i)
        elif d == 0:
            print('*'*(n-i+1))
        else:
            print("SOME UNEXPECTED ERROR OCCURED PLEASE TRY LATER")    
            break
