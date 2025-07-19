from cs50 import SQL

db = SQL("sqlite:///favorites.db")
inp = input("add lang: ")


rows = db.execute("SELECT language, COUNT(language) AS N FROM favorites WHERE language = ?", inp)
row = rows[0]
print(f"{row["language"]} : {row["N"]}")
