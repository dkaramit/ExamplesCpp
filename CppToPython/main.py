from Example import Example


C= Example.calcClass(1.2,5.)


print(
    C.sum(),
    C.mul(),
    C.sumWith(30)
)

del C

try:
    print(
        C.sum(),
        C.mul(),
        C.sumWith(30)
    )
except:
    print("C is deleted")