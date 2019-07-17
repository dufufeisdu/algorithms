def threeSumClosest(nums, target):
    if len(nums) < 3:
        return None
    nums.sort()
    clst = sum(nums[:3])
    dist = clst - target
    for idx, n in enumerate(nums[:-2]):
        i = idx + 1
        j = len(nums) - 1
        while i < j:
            x = nums[idx] + nums[i] + nums[j]
            n_dist = x - target
            print(nums[idx], nums[i], nums[j], "sums:", x)
            if abs(n_dist) < abs(dist):
                dist = n_dist
                clst = x
            if x < target:
                i += 1
            elif x > target:
                j -= 1
            else:
                return clst

    return clst


print(threeSumClosest([1, 2, 4, 8, 16, 32, 64, 128], 82))

