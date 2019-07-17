def findInMountainArray(self, target: int, mountain_arr: "MountainArray") -> int:
    length = mountain_arr.length()
    # left
    sid = 0
    eid = length
    ltid = -1
    rtid = -1
    while sid < eid:
        mid = (sid + eid) // 2
        m_ele = mountain_arr.get(mid)
        pre = mountain_arr.get(mid - 1)
        nxt = mountain_arr.get(mid + 1)
        if pre > m_ele and cur > m_ele:
            eid = mid
        else:
            if target < cur:
                eid = mid
            else:
                sid = mid + 1
    # search right
    sid = 0
    eid = length
    maxid = 1
    find_three_flag = True
    while sid < eid:
        mid = (sid + eid) // 2
        cur = mountain_arr.get(mid)
        if cur == target:
            return mid
        if find_three_flag:
            pre = mountain_arr.get(mid - 1)
            nxt = mountain_arr.get(mid + 1)
        if find_three_flag and pre < cur and cur < nxt:
            sid = mid
        else:
            if cur < target:
                eid = mid
            else:
                sid = mid + 1

    return ltid if ltid != -1 else rtid
