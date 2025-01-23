import json

graph = {
    'Arad': [('Zerind', 75), ('Timisoara', 118), ('Sibiu', 140)],
    'Zerind': [('Arad', 75), ('Oradea', 71)],
    'Oradea': [('Zerind', 71), ('Sibiu', 151)],
    'Timisoara': [('Arad', 118), ('Lugoj', 111)],
    'Lugoj': [('Timisoara', 111), ('Mehadia', 70)],
    'Mehadia': [('Lugoj', 70), ('Dobreta', 75)],
    'Dobreta': [('Mehadia', 75), ('Craiova', 120)],
    'Craiova': [('Dobreta', 120), ('Rimnicu Vilcea', 146), ('Pitesti', 138)],
    'Sibiu': [('Arad', 140), ('Oradea', 151), ('Fagaras', 99), ('Rimnicu Vilcea', 80)],
    'Fagaras': [('Sibiu', 99), ('Bucharest', 211)],
    'Rimnicu Vilcea': [('Sibiu', 80), ('Craiova', 146), ('Pitesti', 97)],
    'Pitesti': [('Rimnicu Vilcea', 97), ('Craiova', 138), ('Bucharest', 101)],
    'Bucharest': [('Fagaras', 211), ('Pitesti', 101), ('Giurgiu', 90), ('Urziceni', 85)],
    'Giurgiu': [('Bucharest', 90)],
    'Urziceni': [('Bucharest', 85), ('Vaslui', 142), ('Hirsova', 98)],
    'Hirsova': [('Urziceni', 98), ('Eforie', 86)],
    'Eforie': [('Hirsova', 86)],
    'Vaslui': [('Urziceni', 142), ('Iasi', 92)],
    'Iasi': [('Vaslui', 92), ('Neamt', 87)],
    'Neamt': [('Iasi', 87)]
}

def depth_limited_search(node, goal, limit, path, current_cost):

    path.append(node)
    if (node == goal):
        return path, current_cost
    if (limit == 0):
        return False, 0
    
    shortest_path = []
    min_cost = 10000
    for successor, cost in graph.get(node):
        if (successor not in path):

            result, child_cost = depth_limited_search(successor, goal, limit-1, path.copy(), cost)

            if result == False:
                shortest_path = False
                continue
            else:
                if (current_cost + child_cost < min_cost):
                    min_cost = current_cost + child_cost
                    shortest_path = result
    return shortest_path, min_cost

def Iterative_depending_deep_limited_search(node, problem):
    for i in range(1000):
        result, cost = depth_limited_search(node,problem, i, [], 0)

        if (result == False):
            continue
        else:
            return result, cost, i

# Searching with deep limited search
root = "Arad"
goal = "Bucharest"
result, cost, limit = Iterative_depending_deep_limited_search(root, goal)
print("Path shorted is: ", result)
print("Min cost is: ", cost)
print("Limit is: ",limit)