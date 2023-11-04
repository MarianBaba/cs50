import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        fav = row["language"]
        if fav in counts:
            counts[fav] += 1  
        else:
            counts[fav] = 1

for key in sorted(counts, key=lambda language: counts[language], reverse=True):
    print(f"{key}: {counts[key]}")