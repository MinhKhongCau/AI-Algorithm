import json

with open('graph_data.json', 'r') as file:
    data = json.load(file)

def depth_limited_search(node, goal, limit, path, current_cost):

    path.append(node)
    if (node == goal):
        return path, current_cost
    if (limit == 0):
        return False, 0
    
    shortest_path = []
    min_cost = 10000
    for successor, cost in data.get(node):
        if (successor not in path):

            result, child_cost = depth_limited_search(successor, goal, limit-1, path.copy(), cost)

            if result != False and current_cost + child_cost < min_cost:
                min_cost = current_cost + child_cost
                shortest_path = result


    return shortest_path, min_cost

# Searching with deep limited search
root = "Arad"
goal = "Bucharest"
depth_limit = 6
path = []
result, cost = depth_limited_search(root, goal, depth_limit, path, 0)
print("Path shorted is: ", result)
print("Min cost is: ", cost)