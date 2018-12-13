import os
from shutil import copyfile


cnt = 1
for file in os.listdir('testdata'):
	if file.endswith('.in'):
		copyfile('testdata/{}.in'.format(file[:-3]), 'toj/res/testdata/{}.in'.format(cnt))
		copyfile('testdata/{}.out'.format(file[:-3]), 'toj/res/testdata/{}.out'.format(cnt))

		cnt += 1
