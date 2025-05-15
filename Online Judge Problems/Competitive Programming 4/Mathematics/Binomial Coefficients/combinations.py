# Combinations (https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=305)

def factorial(x, dp):
    if x == 0:
        return 1
    if dp.get(x, -1) != -1:
        return dp[x]
    dp[x] = x * factorial(x-1, dp)
    return dp[x]

def bin_coeff(n, k, dp):
    numer = factorial(n, dp)
    denom = factorial(n-k, dp) * factorial(k, dp)
    return numer // denom

def main():
    dp = {}
    n, k = map(int, input().split(' '))

    while n > 0 and k > 0:
        coeff = bin_coeff(n, k, dp)
        print(f"{n} things taken {k} at a time is {coeff} exactly.")

        n, k = map(int, input().split(' '))
    

if __name__ == "__main__":
    main()