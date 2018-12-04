import random


random.seed(1337)


for task in range(1, 6):
	for subtask in range(1, 21):
		maxn = 15
		if task == 4:
			maxn = 10

		n = random.randint(1, maxn)

		reversetime = random.randint(0, max(1, n - 5))
		if task == 1 or task == 2:
			reversetime = 1
		if task == 3:
			reversetime = random.randint(0, 4)

		name = "{:02d}{:02d}".format(task, subtask)
		print(name, n, reversetime)

		res = [0] * n
		usedk = []
		print(res)

		for x in range(reversetime):
			i = 100
			k = 100
			while i + k > n:
				i = random.randint(0, n)
				k = random.randint(1, n)
			for p in range(i, i+k):
				res[p] = 1 - res[p]

		if task == 2:
			for p in range(n):
				res[p] = 1 - res[p]
		# print(res)

		# lenof1 = random.randint(0, n)
		# lenof0before1 = random.randint(0, n-lenof1)
		# for i in range(lenof0before1):
		# 	res += "0"
		# for i in range(lenof1):
		# 	res += "1"
		# for i in range(n-lenof1-lenof0before1):
		# 	res += "0"

		print(res, len(res))
		with open("testdata/{}.in".format(name), "w") as f:
			f.write("".join(map(str, res))+"\n")

		print("-----")
		# input()
