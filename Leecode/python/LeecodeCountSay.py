#/usr/bin/env python3
# 1,11,21,1211,111221
# mistake 0: pathlogic case
# mistake 1: string is not changable
# mistake 2: should use try and except to handle out range
# improve 3: could use a label and not use two while loop


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
        flag_enter = True
        count = 0
        while y < len_numb:
            count += 1
            if flag_enter:
                if len_numb == y + 1:
                    numb_c += str(count)
                    numb_c += numb[y]
                    break
                elif numb[y + 1] != numb[y]:
                    numb_c += str(count)
                    numb_c += numb[y]
                    flag_enter = False

            else:
                count = 0
                flag_enter = True
                y -= 1
            y += 1
        numb = numb_c
    return numb


print(count_and_say(7))
