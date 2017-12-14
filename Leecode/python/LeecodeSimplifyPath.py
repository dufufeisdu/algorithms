#/usr/bin/env python3
''' /home/=>/home
    /a/./b/../../c/ => /c
    /=>/
    /home//foo/ =>/home/foo
    error:
    a
    /a/../../

'''


def interpater_next(path, simp_path, x):


def simplify_path(path):
    simp_path = ''
    path_len = len(path)

    if path[0] != '/':
        return 'ERROR'
    x = 0
    flag = True
    segment = ""
    while x < path_len:
        # incorrect path /../
        if flag:
            if path[x] != '/':
                segment += path[x]
            else:
                flag = False

        x += 1
    return simp_path
