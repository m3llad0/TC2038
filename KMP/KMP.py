""""
KMP search algorithm

Tonatiuh Reyes
Diego Mellado
Iwalani Amador
"""

def findPrefix(pattern, M, prefixArr):
    # Length and prefix array starts in zero
    len = 0
    prefixArr[0]
    # i starts in 1
    i = 1

    while i < M:
        # Compares the first letter at position i and letter at second len
        # i.e patter[1] == pattern[0] -> A == A
        if pattern[i] == pattern[len]:
            len += 1
            # Adds len add position i
            prefixArr[i] = len
            i += 1
        else:
            if len != 0:
                # length new value 
                len = prefixArr[len - 1]
            else:
                # set prefix Array i position to zero
                prefixArr[i] = 0
                i += 1


def KMPSearch(pattern, mainText, locArray, loc):
    # Pattern length
    M = len(pattern)
    # String legnth
    N = len(mainText)

    # Sets the prefix array length of the array with patter length
    prefixArr = [0]*M
    j = 0
    i = 0
    findPrefix(pattern, M, prefixArr)

    while (N - i) >= (M - j):
        # Comapares pattern at j position and mainText at i position 
        if pattern[j] == mainText[i]:
            # if coincides i and j sums one
            i += 1
            j += 1
        if j == M:
            # if j and M are equal, appends the position at the array
            loc += 1
            locArray.append(i - j)
            # Sets j value as the position result of j - 1 of the prefix array
            j = prefixArr[j - 1]

        # Checks if i is smaller than N and patter at position j is different than string at position i
        elif i < N and pattern[j] != mainText[i]:
            if j != 0:
                # Sets j as the number result of the position j - 1
                j = prefixArr[j - 1]
            else:
                i += 1

    print("Coincidences found at positions", locArray)

def main():
    text = "ABABDABACDABABCABAB"
    pat = "AB"
    localArr = []

    KMPSearch(pat, text, localArr, loc = 0)

main()
