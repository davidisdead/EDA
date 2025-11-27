def fibonacci(n, memo={}):
    if n in memo:
        return memo[n]
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo)
    return memo[n]


# Posiciones solicitadas
posiciones = [7, 21, 40, 71, 94]

for p in posiciones:
    print(f"Fibonacci({p}) = {fibonacci(p)}")