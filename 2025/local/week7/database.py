import csv

with open("C:\\Users\\mousa\\Desktop\\Home\Mousa\\codehub\\cs50\\local\\week7\\favorites.csv", "r") as file:
    read = csv.DictReader(file)
    counts = {}
    for row in read:
        fav = row["language"]
        if fav in counts:
            counts[fav] += 1
        else:
            counts[fav] = 1
print("+----------+")
for fav in sorted(counts):
    print(f"{fav} : {counts[fav]}")
print("+----------+")