P = 1019
g = 3
q = 509

# load g^a and g^b from the provided Excel file
# removed my wsu id lol
wsuid = 123456789
g_a = 469
g_b = 601

# brute force approach to find a and b
for a in range(q):
    if pow(g, a, P) == g_a:
        for b in range(q):
            if pow(g, b, P) == g_b:
                # found matching pairs, calculate g^ab
                g_ab = pow(g, (a*b) % q, P)
                print("WSUID: ", wsuid)
                print("g^a: ", g_a)
                print("g^b: ", g_b)
                print("g^ab: ", g_ab)
                break
            break
