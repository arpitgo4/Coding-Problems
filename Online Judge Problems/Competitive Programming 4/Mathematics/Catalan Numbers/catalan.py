
# catalan (https://open.kattis.com/problems/catalan)

# Time: O(N)
# Space: O(N)

MAX_NUM = 5000 * 2

factorials = {}

def pre_process_factorials():
    factorials[0] = 1
    for i in range(1, MAX_NUM+1):
        factorials[i] = i * factorials[i-1]

def catalan(x):
    numer = factorials[2 * x]
    denom = factorials[x] * factorials[x] * (x + 1)
    return numer // denom

def main():
    pre_process_factorials()
    num_cnt = int(input())
    for i in range(num_cnt):
        x = int(input())
        result = catalan(x)
        print(result)

if __name__ == "__main__":
    main()
