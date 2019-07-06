import random
from functools import reduce
import copy

field_size = 3

# pandas


def makelist():
    return [random.randint(0, 1) for i in range(field_size)]

def count_cell(field, x, y):
    return reduce(lambda a, b: a + b, [reduce(lambda a, b: a + b, field[i][x-1:x+2]) for i in range(y-1, y+2)]) - field[y][x]

def update_cell(old_field, new_field, x, y):
    alive = count_cell(old_field, x, y)
    if old_field[y][x] == 1 && (alive < 2 || alive > 3):
        new_field[y][x] = 0
    elif old_field[y][x] == 0 && alive == 3:
        new_field[y][x] = 1

def update(field):
    next_field = copy.deepcopy(field)
    for y, a in enumerate(field):
        for x, b in enumerate(a):
            update_cell(field, next_field, x, y)
    field = next_field    

field = [makelist() for i in range(field_size)]
print(field)



x = 1
y = 1
count = 
print(count)


