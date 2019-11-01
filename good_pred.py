n,w,t,r = map(int,input().split(" "))
# print(n,w,t,r)
if n==0:
	print("0")
else:
	mod  = int(1e9+7)
	fib = 1000*[0]
	fib[0] = 1
	fib[1] = 1
	for i in range(2,1000):
		fib[i]= (i%mod * fib[i-1]%mod )%mod

	num = fib[n]
	num /= fib[w]
	num /= fib[t]
	num /= fib[r]
	num %= mod
	print(int(num))