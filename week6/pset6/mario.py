def main():
    height = int(input("Height: "))
    mariov1(height)
    mariov2(height)

def mariov1(height):
    for i in range(1, height + 1):
        for j in range(height - i):
            print(" ", end="")
        for k in range(i):
            print("#", end="")
        print()

def mariov2(height):
    for i in range(1, height + 1):
        for j in range(height - i):
            print(" ", end="")
        for k in range(i):
            print("#", end="")
        print(" ", end="")
        for h in range(i):
            print("#", end="")
        print()


main()