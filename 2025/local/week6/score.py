scores = [] 

n = int(input("sum of celsce: "))

for i in range(n):
    entry = input("entry: ")  
    scores.append(entry) # or can use scores += [entry]

for i in range(n):
    print(f"{scores[i]}")
