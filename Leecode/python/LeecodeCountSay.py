#/usr/bin/env python3
# 1,11,21,1211,111221
# mistake 0: pathlogic case
# mistake 1: string is not changable
# mistake 2: should use try and except to handle out range


def count_and_say(n):
    # for loop
    # while loop
    #   count how many same number after
    #   replace string with new one
    numb = '1'
    if n == 0:
        return ''
    if n == 1:
        return numb
    for x in xrange(2, n + 1):
        len_numb = len(numb)
        y = 0
        numb_c = ''
        while y < len_numb:
            start = y
            count = 1
            while True:
                try:
                    temp = numb[y + 1]
                    if temp == numb[y]:
                        count += 1
                        y += 1
                    else:
                        numb_c += str(count)
                        numb_c += numb[start]
                        y += 1
                        break
                except IndexError:
                    y += 1
                    numb_c += str(count)
                    numb_c += numb[start]
                    break
        numb = numb_c
    return numb


print(count_and_say(6))
