import os

for file in os.listdir('testdata'):
	if file.endswith('.in'):
		print(file)
		cmd = 'main.exe < testdata/{} > testdata/{}'.format(file, file[:-3]+'.out')
		os.system(cmd)
