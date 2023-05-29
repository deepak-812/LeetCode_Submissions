class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = len(s)
        i = 0
        j = 0
        ans = 0
        vis = [False] * 256

        while j < length:
            if vis[ord(s[j])]:
                while s[i] != s[j]:
                    vis[ord(s[i])] = False
                    i += 1
                if s[i] == s[j]:
                    vis[ord(s[i])] = False
                    i += 1
            vis[ord(s[j])] = True
            ans = max(j - i + 1, ans)
            j += 1

        ans = max(j - i, ans)
        return ans
        