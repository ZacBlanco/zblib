import os
import sys
import subprocess

if __name__ == "__main__":
    mypath = os.path.dirname(os.path.abspath(__file__))
    files = os.listdir(mypath)
    for f in files:
        # For every file we need to compile and execute
        if f[-2:] == '.c' and 'test.c' not in f:
            # print("Compiling {}".format(f))
            extra_files = []
            with open(mypath + '/' + f, mode='r') as fi:
                lns = fi.readlines()
                for line in lns:
                    if '#include' in line and '../src' in line and '.h"'  in line:
                        ef = '../' + line[line.index('/')+1:].replace('"', '').replace('.h', '.c')
                        extra_files.append(ef.strip())
            p = subprocess.Popen(['gcc', mypath + '/' + f, 'test.c'] + extra_files,
                                 cwd='./test/')
            p.wait()
            if p.returncode == 0:
                p = subprocess.Popen(['./a.out'], cwd='./test/')
                p.wait()
            else:
                print("Error compiling {}".format(f))
        