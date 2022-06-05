ipl = {}

n = int(input("Enter no.of teams : "))

for i in range(n):

    tname = input('Enter the team name : ')

    p1 = input('Enter name of player 1 : ')

    p2 = input('Enter name of player 2 : ')

    p3 = input('Enter name of player 3 : ')

    ipl[tname] = (p1, p2, p3)

print(ipl)

team = input('Enter team name whose players are to be displayed : ')

for k in ipl:

    if team == k:

        for l in range(len(ipl[k])):

            print(ipl[k][l])

pname = input('Enter the player name whose team is to be displayed : ')

for a in ipl:

    for b in range(len(ipl[a])):

        if ipl[a][b] == pname:

            print('The player', pname, 'is in team', a)
