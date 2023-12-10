WIDTH, HEIGHT = 9, 8

stacks = tuple([] for _ in range(WIDTH))  # creating WIDTH amount of lists inside the tuple

input = open('input1.txt', 'r')

for row in range(HEIGHT): # reading first lines

    line = input.readline()

    for column in range(WIDTH):
        char = line[4*column + 1] # getting the capital letters, skipping others
        if char != ' ':
            stacks[column].append(char)
    
for stack in stacks:
    stack.reverse()

# progressing through empty/irrelevant lines
input.readline()
input.readline()

for line in input:

    s = line.split()

    src = int(s[3]) - 1
    dest = int(s[5]) - 1
    amount = int(s[1])

    for _ in range(amount):
        stacks[dest].append(stacks[src].pop())

print('\nANSWER: ' + ''.join(stack[-1] for stack in stacks))
