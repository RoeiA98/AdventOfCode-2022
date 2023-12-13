WIDTH, HEIGHT = 9, 8

stacks = [[] for _ in range(WIDTH)]  # creating WIDTH amount of lists inside the list

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

        # slicing lists
        stacks[dest] += stacks[src][-amount:]   # adding the values to destination
        stacks[src] = stacks[src][:-amount]     # cutting the source accordingly

    print('\nANSWER: ' + ''.join(stack[-1] for stack in stacks))
