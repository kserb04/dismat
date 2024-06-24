from math import factorial as fact


def binomial(a, b):
    result = 1
    if b < 0:
        return 0
    for i in range(a, a - b, -1):
        result *= i
    result = result // fact(b)
    return result


def multiply(p_1, p_2, p_tot, m):
    for i in range(0, len(p_1)):
        if p_1[i] != 0:
            for j in range(0, len(p_2)):
                if i + j <= m and p_2[j] != 0:
                    p_tot[i + j] += p_1[i] * p_2[j]
    return p_tot


def calculate(a_s, m):
    nonzero = len(a_s)
    ps = []
    for a in a_s:
        if a != 0:
            p_a = [0 for _ in range(a + 2)]
            p_a[0] = 1
            p_a[a + 1] = -1
        else:
            p_a = [1]
            nonzero -= 1
        ps.append(p_a)

    a_total = a_s.pop(0) + a_s.pop(0) + 3
    p_in = [0 for i in range(a_total)]
    p_out = multiply(ps.pop(0), ps.pop(0), p_in, m)

    while len(ps):
        p_next = ps.pop(0)
        a_total += a_s.pop(0) + 1
        p_in = [0 for _ in range(a_total)]
        p_out = multiply(p_out, p_next, p_in, m)

    res = 0

    for i in range(0, len(p_in)):
        if p_in[i] == 0:
            continue
        res += p_in[i] * binomial(nonzero - 1 + m - i, nonzero - 1)
    return res


if __name__ == "__main__":
    # input
    m = int(input("Enter nonnegative integer m: "))
    a_1 = int(input("Enter nonnegative integer a_1: "))
    a_2 = int(input("Enter nonnegative integer a_2: "))
    a_3 = int(input("Enter nonnegative integer a_3: "))
    a_4 = int(input("Enter nonnegative integer a_4: "))
    a_s = [a_1, a_2, a_3, a_4]
    result = calculate(a_s, m)
    print(f"Number of solutions: {result}")
