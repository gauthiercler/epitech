#!/usr/bin/python3

from pprint import pprint
from collections import deque
import datetime


def at(x, y):
    # print("at")
    # print("%r %r" % (x, y))
    return map[y][x]


def print_pos(x, y):
    # print('Pos X: %r Y: %r' % (x, y))
    return

def print_map():
    for y in range(len(map)):
        for x in range(len(map[y])):
            print(at(x, y), end=', ')
        print("\n")


def can_move(x, y):
    if at(x, y) == Item.bonus or at(x, y) == Item.empty:
        return True
    return False


def get_heuristic(first, second):
    return abs(first.x - second.x) + abs(first.y - second.y)


def get_closest_item(pos, item):
    res = Position(-1, -1)
    for y in range(len(map)):
        for x in range(len(map[y])):
            if at(x, y) == item and (pos.x != x or pos.y != y) and\
                (get_heuristic(pos, Position(x, y)) < get_heuristic(pos, res) or
                     (res.x == -1 and res.y == -1)):
                res.x = x
                res.y = y
    return res


def is_breakable_cell(item):
    return\
        item == Item.bonus or\
        item == Item.empty or\
        item == Item.player or\
        item == Item.fire


def set_cell(x, y, item):
    if 0 <= x < len(map[0]) and 0 <= y < len(map):
        map[y][x] = item


def check_is_dangerous(x, y):
    if 0 <= x < len(map[0]) and 0 <= y < len(map):
        if is_breakable_cell(at(x, y)):
            set_cell(x, y, Item.fire)


def is_safe_cell(item):
    return item == Item.bonus or item == Item.empty or item == Item.player


def gen_graph(maze):
    height = len(maze)
    width = len(maze[0]) if height else 0
    graph = {(i, j): [] for j in range(width)
             for i in range(height) if not maze[i][j]}
    for row, col in graph.keys():
        if row < height - 1 and not maze[row + 1][col]:
            graph[(row, col)].append(("S", (row + 1, col)))
            graph[(row + 1, col)].append(("N", (row, col)))
        if col < width - 1 and not maze[row][col + 1]:
            graph[(row, col)].append(("E", (row, col + 1)))
            graph[(row, col + 1)].append(("W", (row, col)))
    return graph


def find_path_bfs(map, target_x, target_y):
    # print_pos(target_x, target_y)
    start = (player_pos.y, player_pos.x)
    if map[player_pos.y][player_pos.x] == 1:
        return ""
    goal = (target_y, target_x)
    queue = deque([("", start)])
    visited = set()
    graph = gen_graph(map)
    while queue:
        path, current = queue.popleft()
        if current == goal:
            return path
        if current in visited:
            continue
        visited.add(current)
        for direction, neighbour in graph[current]:
            queue.append((path + direction, neighbour))
    return ""


def display_map():
    for y in range(len(map)):
        for x in range(len(map[y])):
            pprint(map[y][x])


def convert_map():
    for y in range(len(map)):
        for x in range(len(map[y])):
            item = at(x, y)
            if item == Item.brick or item == Item.box or item == Item.fire:
                path_map[y][x] = 1
            else:
                path_map[y][x] = 0
    path_map[player_pos.y][player_pos.x] = 0
    # pprint(path_map)


def convert_safe_map():
    #print("%r %r" % (len(map), len(map[0])))
    for y in range(len(map)):
        for x in range(len(map[y])):
            item = at(x, y)
            if item == Item.brick or item == Item.box or item == Item.bomb or item == Item.fire or item == Item.future_fire:
                path_map[y][x] = 1
            else:
                path_map[y][x] = 0
    path_map[player_pos.y][player_pos.x] = 0
    path_map[last_target.y][last_target.x] = 0



def get_dir_by_coordinates(coordinate):
    # print(coordinate)
    if coordinate == 'N':
        return Action.up
    if coordinate == 'S':
        return Action.down
    if coordinate == 'W':
        return Action.left
    if coordinate == 'E':
        return Action.right


def find_path():
    offset = 1
    length = (max(len(map), len(map[0])))
    if length > 5:
        length = 5;
    count = 0
    while offset < length:
        y = player_pos.y - offset
        while y < player_pos.y + offset:
            x = player_pos.x - offset
            while x < player_pos.x + offset:
                if 0 <= x < len(map[0]) and 0 <= y < len(map):
                    if x != player_pos.x or y != player_pos.y:
                        if is_safe_cell(at(x, y)):
                            if count >= 10:
                                return Action.nothing
                            count += 1
                            convert_map()
                            res = find_path_bfs(path_map, x, y)
                            if res != "":
                                return assess_found_path(res, x, y)
                x += 1
            y += 1
        offset += 1
    set_target(-1, -1)
    return Action.nothing


def is_box(x, y):
    if 0 <= x < len(map[0]) and 0 <= y < len(map):
        if at(x, y) == Item.box:
            return True
    return False


def has_adjacent_box(x, y):
    if is_box(x + 1, y)\
        or is_box(x - 1, y)\
        or is_box(x, y + 1)\
        or is_box(x, y - 1):
        return True
    return False


def set_target(x, y):
    last_target.x = x
    last_target.y = y


def find_box():
    # print("find box")
    offset = 1
    count = 0
    length = (max(len(map), len(map[0])))
    while offset < length:
        y = player_pos.y - offset
        while y < player_pos.y + offset:
            x = player_pos.x - offset
            while x < player_pos.x + offset:
                if 0 <= x < len(map[0]) and 0 <= y < len(map):
                    if x != player_pos.x or y != player_pos.y:
                        if at(x, y) == Item.box:
                            if count >= 10:
                                return Action.nothing
                            count += 1
                            convert_safe_map()
                            path_map[y][x] = 0
                            res = find_path_bfs(path_map, x, y)
                            if res != "":
                                return assess_found_path(res, x, y)
                x += 1
            y += 1
        offset += 1
    set_target(-1, -1)
    return Action.bomb


def assess_found_path(ret, x, y):
    if len(ret) > 1:
        set_target(x, y)
    else:
        set_target(-1, -1)
    return get_dir_by_coordinates(ret[:1])


def compute(input_map, input_pos):
    global map
    global path_map
    global player_pos

    path_map = [[0 for _ in range(len(input_map[0]))]
                for _ in range(len(input_map))]
    player_pos = input_pos
    map = input_map
    #pprint(map)

    # find_explosions(player_pos)

    # check if current cell is safe
    if is_safe_cell(at(player_pos.x, player_pos.y)) is not True:
        # print("Position %r %r not safe" % (player_pos.x, player_pos.y))
        # check if last target is defined and safe

        if last_target.x != -1 and last_target.y != -1 and is_safe_cell(at(last_target.x, last_target.y)):
            # print("Last target is %r %r" % (last_target.x, last_target.y))
            convert_map()
            path_map[last_target.y][last_target.x] = 0
            # pprint(path_map)
            ret = find_path_bfs(path_map, last_target.x, last_target.y)
            # if path is valid return direction
            if ret != "":
                # if has only one instruction set last target as undefined
                # pprint(ret)
                return assess_found_path(ret, last_target.x, last_target.y)
            else:
                # print("Path %r %r is blocked")
                return find_path()
        else:
            return find_path()

    if has_adjacent_box(player_pos.x, player_pos.y):
        return Action.bomb

    # print("Find box")
    if last_target.x != -1 and last_target.y != -1 and at(last_target.x, last_target.y) == Item.box:
        convert_safe_map()
        ret = find_path_bfs(path_map, last_target.x, last_target.y)
        if ret != "":
            return assess_found_path(ret, last_target.x, last_target.y)
        else:
            return find_box()
    else:
        return find_box()

