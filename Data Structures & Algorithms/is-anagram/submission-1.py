class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if not(len(s) == len(t)):
            return False

        myList = []
        for i in range(len(s)):
            myList.append(s[i])

        
        for j in range(len(t)):
            if t[j] in myList:
                myList.remove(t[j])
            else:
                return False
        
        return True
        