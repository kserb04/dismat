def any_not_visited(visited, n):
    return any(visited[i] == 0 for i in range(n))


def calculate_weight(a, b, c, i, j):
    p = abs(i - j) % c
    return pow(a, p) + b * pow(i - j, 2) - 1


def find_min(distances, exclude):
    arr = [(i, d) for (i, (exc, d)) in enumerate(zip(exclude, distances)) if not exc]
    min_index, min_distance = min(arr, key=lambda x: x[1])
    return min_distance, min_index


def solve(n, a, b, c, k, l):
    path = [k - 1]  # path to follow

    weight_matrix = [[0 for _ in range(n)] for _ in range(n)]
    min_distance = 0
    min_index = 0

    for i in range(n):
        for j in range(n):
            weight_matrix[i][j] = calculate_weight(a, b, c, i, j)

    visited = [False for _ in range(n)]
    distances = weight_matrix[k - 1][::]

    # starting node k is visited
    visited[k - 1] = True

    while any_not_visited(visited, n):
        # find min distance node
        min_distance, min_index = find_min(distances, visited)
        visited[min_index] = True
        if min_index == l - 1:
            path.append(min_index)
            print(f"Direct distance: {weight_matrix[k - 1][l - 1]}")
            for s, e in zip(path, path[1:]):
                print(f"{s+1} -> {e+1}: len {weight_matrix[s][e]}")
            return distances[l - 1]

        for i in range(n):
            if visited[i]:
                continue

            new_distance = min_distance + weight_matrix[min_index][i]
            if new_distance < distances[i]:
                # new distance is shorter - update
                distances[i] = new_distance
                if i == l - 1:
                    path.append(min_index)


if __name__ == "__main__":
    # input
    n = int(input("Enter number of vertices: "))
    a = int(input("Enter first param: "))
    b = int(input("Enter second param: "))
    c = int(input("Enter third param: "))
    while True:
        k = int(input(f"Enter first vertex (1-{n}): "))
        if k > n:
            print("Wrong input")
        else:
            break
    while True:
        l = int(input(f"Enter second vertex (1-{n}): "))
        if l > n:
            print("Wrong input")
        else:
            break
    solution = solve(n, a, b, c, k, l)
    print(f"Minimal distance is {solution}")
