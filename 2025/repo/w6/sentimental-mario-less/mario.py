# from cs50 import get_int

def main():
    while True:
        # height = get_int("Height: ")
        height = int(input("Height: "))
        space = 0
        if height >= 1 and height <= 8:
            pr(height, space)
            break


def pr(h, space):

    if h == 0:
        return
    pr(h -1, space +1)
    for j in range(space):
        print(" ", end="")
        space = space + 1
    for i in range(h):
        print("#", end="")
    print("")
main()
