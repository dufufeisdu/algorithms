def lengthOfLongestSubstring(s):
        """
        :type s: str
        :rtype: int
        """
        if len(s)<=1:
            return len(s);
        maxsub_len = 1;
        i=0
        while i<len(s):
            j=i;
            str_dict = {};
            sub_len=0
            while str_dict.get(s[j])==None:

                str_dict[s[j]]=j
                sub_len+=1
                j+=1
                if len(s)==j:
                    break

            if sub_len>maxsub_len:
                maxsub_len = sub_len
            if j>=len(s):
                return maxsub_len
            i=str_dict[s[j]]+1
        return maxsub_len

print(lengthOfLongestSubstring("abca"))
