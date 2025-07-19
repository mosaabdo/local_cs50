names = ["mousa", "ahmed", "kaled"]

name = input("name: ")

for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not Found")