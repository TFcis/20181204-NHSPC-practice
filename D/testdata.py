import random

task = 1
for subtask in range(1, 21):
	name = "{:02d}{:02d}".format(task, subtask)
	print(name)
	
	n = random.randint(1, 8)
	k = random.randint(0, n-1)

	with open("testdata/{}.in".format(name), "w") as f:
		f.write("{} {}\n".format(n, k))

	print("-----")
	
task = 2
for subtask in range(1, 21):
	name = "{:02d}{:02d}".format(task, subtask)
	print(name)
	
	n = random.randint(1, 257)
	k = n-1

	with open("testdata/{}.in".format(name), "w") as f:
		f.write("{} {}\n".format(n, k))

	print("-----")
	
task = 3
for subtask in range(1, 21):
	name = "{:02d}{:02d}".format(task, subtask)
	print(name)
	
	n = random.randint(1, 100000)
	k = 0

	with open("testdata/{}.in".format(name), "w") as f:
		f.write("{} {}\n".format(n, k))

	print("-----")
	
task = 4
for subtask in range(1, 21):
	name = "{:02d}{:02d}".format(task, subtask)
	print(name)
	
	n = random.randint(1, 2000)
	k = random.randint(0, min(n-1, 10))

	with open("testdata/{}.in".format(name), "w") as f:
		f.write("{} {}\n".format(n, k))

	print("-----")
	
task = 5
for subtask in range(1, 21):
	name = "{:02d}{:02d}".format(task, subtask)
	print(name)
	
	n = random.randint(1, 100000)
	k = random.randint(0, n-1)

	with open("testdata/{}.in".format(name), "w") as f:
		f.write("{} {}\n".format(n, k))

	print("-----")
	