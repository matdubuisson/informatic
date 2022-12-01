def is_prime(n):
  # e = 1; while e < n // 2: ...
  for i in range(1, n // 2 + 1):
    if n % i == 0:
      return False
  return True
