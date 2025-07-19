from sys import argv

if len(argv) == 2:
    print(f"Hello, {argv[1]}")
elif len(argv) != 2:
    print("Error: Missing command argument")
    exit