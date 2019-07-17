class Solution:
    def big_add(self, num1, num2):
        size = 18
        n1, n2 = len(num1), len(num2)
        if n1 <= size and n2 <= size:
            return str(int(num1) + int(num2))
        elif n1 > size and n2 < size:
            a, b = num1[:-size], num1[-size:]
            c = num2
            bc = self.big_add(b, c)
            if len(bc) > size:

                return self.big_add(a, bc[0]) + bc[1:]
            else:
                return a + "0" * (size - len(bc)) + bc
        elif n1 <= size and n2 > size:
            return self.big_add(num2, num1)
        else:
            a, b = num1[:-size], num1[-size:]
            c, d = num2[:-size], num2[-size:]
            bd = self.big_add(b, d)
            ac = self.big_add(a, c)
            if len(bd) > size:
                return self.big_add(ac, bd[0]) + bd[1:]
            else:
                return ac + "0" * (size - len(bd)) + bd

    def multiply(self, num1, num2):
        size = 9
        n1, n2 = len(num1), len(num2)
        if n1 <= size and n2 <= size:
            return str(int(num1) * int(num2))
        elif n1 > size and n2 <= size:
            a, b = num1[:size], num1[size:]
            c = num2
            ac = self.multiply(a, c) + "0" * (n1 - size)
            bc = self.multiply(b, c)
            return self.big_add(ac, bc)
        elif n1 <= size and n2 > size:
            a, b = num2[:size], num2[size:]
            c = num1
            ac = self.multiply(a, c) + "0" * (n2 - size)
            bc = self.multiply(b, c)
            return self.big_add(ac, bc)
        else:
            a, b = num1[:size], num1[size:]
            c, d = num2[:size], num2[size:]
            ac = self.multiply(a, c) + "0" * (n1 + n2 - 2 * size)
            ad = self.multiply(a, d) + "0" * (n1 - size)
            cb = self.multiply(c, b) + "0" * (n2 - size)
            bd = self.multiply(b, d)
            return self.big_add(self.big_add(self.big_add(ac, ad), cb), bd)


print(Solution().multiply("9992123123123123123", "9991231134134141341233"))

