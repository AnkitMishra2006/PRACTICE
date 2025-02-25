def codelan():
    st = input("SPILL THE BEANS:- ")

    st1 = ""

    for i in st:

        if (ord(i) > 65 and ord(i) <= 90) or (ord(i) > 97 and ord(i) <= 122):
            i = chr(ord(i)-1)
        elif ord(i) == 65:
            i = 'Z'
        elif ord(i) == 97:
            i = 'z' 
        else:
            pass
        st1 += i

    code = st1[::-1]

    return code
print(codelan())
