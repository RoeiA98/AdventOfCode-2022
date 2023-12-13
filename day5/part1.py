WIDTH, HEIGHT = 9, 8

stacks = tuple([] for _ in range(WIDTH))  # creating WIDTH amount of lists inside the tuple

with open('input1.txt', 'r') as input:

    for row in range(HEIGHT): # reading first lines

        line = input.readline()

        for col in range(WIDTH):
            char = line[4*col + 1] # getting the capital letters, skipping other characters
            if char != ' ':
                stacks[col].append(char)
        
    for stack in stacks:
        stack.reverse()

    # progressing through empty/irrelevant lines
    input.readline()
    input.readline()

    for line in input:

        s = line.split()
        src, dest, amount = int(s[3]) - 1, int(s[5]) - 1, int(s[1])

        for _ in range(amount):
            stacks[dest].append(stacks[src].pop())


    print('\nANSWER: ' + ''.join(stack[-1] for stack in stacks))
