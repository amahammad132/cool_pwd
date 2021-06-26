#!/usr/bin/env python
import os, sys

def splitall(path: str):
    allparts = []
    while 1:
        parts = os.path.split(path)
        if parts[0] == path:  # sentinel for absolute paths
            allparts.insert(0, parts[0])
            break
        elif parts[1] == path: # sentinel for relative paths
            allparts.insert(0, parts[1])
            break
        else:
            path = parts[0]
            allparts.insert(0, parts[1])
    return allparts

def colorize(inp: str) -> str:
    return "\033[38;2;102;217;239m" + inp + "\033[0;10m"


def main():
    pwd = sys.argv[1]

    dirs = splitall(pwd)
    dirs.pop(0)
    dirs[0] = '/' + dirs[0]

    ind = 0
    for path_part in dirs[:-1]:
        print(colorize(path_part))
        print(f"{(' ' * 4 * ind)}└── ", end='')
        ind += 1

    print(colorize(dirs[-1]))

if __name__ == '__main__':
    main()
