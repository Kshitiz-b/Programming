from pprint import pprint
Brand = {"Dell": 40000, "HP": 42000, "Lenovo": 40180, "Sony": 39400, "Acer": 39300}
Quantity = {"Dell": 10, "HP": 100, "Lenovo": 50, "Sony": 4, "Acer": 2}
amount = 0
l = [0, 0, 0, 0, 0]
while True:
    x = input('')
    if x == "stop":
        break
    y = int(input(''))

    if x == "Dell" or x == "dell":
        if l[0] == 0:
            l[0] = 1
        if y > Quantity["Dell"]:
            print("STOCK INSUFFICIENT")
        else:
            amount += y*Brand["Dell"]
            Quantity["Dell"] -= y

    elif x == "HP" or x == 'hp':
        if l[1] == 0:
            l[1] = 1
        if y > Quantity["HP"]:
            print("STOCK INSUFFICIENT")
        else:
            amount += y*Brand["HP"]
            Quantity["HP"] -= y

    elif x == "Lenovo" or x == "lenovo":
        if l[2] == 0:
            l[2] = 1
        if y > Quantity["Lenovo"]:
            print("STOCK INSUFFICIENT")
        else:
            amount += y * Brand["Lenovo"]
        Quantity["Lenovo"] -= y
    elif x == "Acer" or x == 'acer':
        if l[3] == 0:
            l[3] = 1
        if y > Quantity["Acer"]:
            print("STOCK INSUFFICIENT")
        else:
            amount += y * Brand["Acer"]
            Quantity["Acer"] -= y
    elif x == "Sony" or x == "sony":
        if l[4] == 0:
            l[4] = 1
        if y > Quantity["Sony"]:
            print("STOCK INSUFFICIENT")
        else:
            amount += y * Brand["Sony"]
            Quantity["Sony"] -= y
    else:
        print("NOT AVAILABLE")

m = {}
if l[0] == 1:
    m["Dell"] = 40000
if l[1] == 1:
    m["HP"] = 42000
if l[2] == 1:
    m["Lenovo"] = 40180
if l[3] == 1:
    m["Sony"] = 39400
if l[4] == 1:
    m["Acer"] = 39300
pprint(m)
print(amount)
