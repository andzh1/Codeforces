import sys
import os
import shutil

size = len(sys.argv) - 1

name = str()
args = sys.argv
args[-1] = '#' + args[-1]
for i in range(size):
    name += args[i + 1]
    if i != size - 1:
        name += ' '

print(name)
cf_folder = '/home/andrey/workspace/Codeforces/'

shutil.copytree(cf_folder + 'templates', cf_folder + name)
shutil.copy(cf_folder + 'templates/template.cpp', cf_folder + name + '/A.cpp')
