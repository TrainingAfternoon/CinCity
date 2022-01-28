tower = input()
split_tower = tower.split('|')
if len(split_tower) % 2 != 0 and split_tower.index('()') == len(split_tower)//2:
    print('correct')
else:
    print('fix')
