"""
Wrote a version in Python to test the concept as well as troubleshoot code.
The version I wrote in Python is much clearer than the vesrion I wrote in C.
"""
#grid = [
#    ["A", "B"],
#    ["B", "A"]
#]

grid = [
     ["J", "Z", "I", "D", "O"],
     ["E", "T", "H", "N", "E"],
     ["E", "R", "Z", "T", "R"],
     ["M", "D", "P", "K", "O"],
     ["A", "T", "F", "R", "A"]
]  # DETER

# grid = [
#     ['W', 'E', 'B', 'M', 'O'],
#     ['I', 'L', 'H', 'L', 'L'],
#     ['M', 'L', 'Z', 'E', 'L'],
#     ['M', 'Y', 'E', 'K', 'O'],
#     ['A', 'O', 'A', 'B', 'A']
# ] #HELLO

# grid = [
#     ['J', 'Z', 'I', 'M', 'O', 'B'],
#     ['O', 'T', 'H', 'N', 'G', 'A'],
#     ['E', 'R', 'B', 'Q', 'P', 'W'],
#     ['M', 'A', 'E', 'K', 'O', 'Z'],
#     ['A', 'T', 'N', 'R', 'A', 'E'],
#     ['E', 'N', 'O', 'B', 'T', 'K']
# ] #BANANA

# grid = [
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"],
#     ["C", "H", "A", "R", "A", "C", "T", "E", "R",
#         "I", "S", "T", "I", "C", "A", "L", "L", "Y"]
# ] #CHARACTERISTICALLY
word = "DETER"

TRUE_PATH = []
ans = [[0] * len(grid) for i in range(len(grid))]


def helper(grid, word, i, j, index, path):
    global TRUE_PATH
    if grid[i][j] == word[index]:
        path[index] = (i, j)
        if index + 1 == len(word):
            TRUE_PATH = path
            return True
        if i > 0:
            if helper(grid, word, i - 1, j, index + 1, path[:]):
                return True
        if j > 0:
            if helper(grid, word, i, j - 1, index + 1, path[:]):
                return True
        if i < len(grid) - 1:
            if helper(grid, word, i + 1, j, index + 1, path[:]):
                return True
        if j < len(grid) - 1:
            if helper(grid, word, i, j + 1, index + 1, path[:]):
                return True
        if ((i > 0) and (j > 0)):
            if helper(grid, word, i - 1, j - 1, index + 1, path[:]):
                return True
        if ((i < len(grid) - 1) and (j < len(grid) - 1)):
            if helper(grid, word, i + 1, j + 1, index + 1, path[:]):
                return True
        if ((i < len(grid) - 1) and (j > 0)):
            if helper(grid, word, i + 1, j - 1, index + 1, path[:]):
                return True
        if ((i > 0) and (j < len(grid) - 1)):
            if helper(grid, word, i - 1, j + 1, index + 1, path[:]):
                return True
    else:
        return False


def wordsearch(grid, word):
    global TRUE_PATH
    global ans
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            helper(grid, word, i, j, 0, [0] * len(word))
            if TRUE_PATH:
                TRUE_PATH = reversed(TRUE_PATH)
                for index, pair in enumerate(TRUE_PATH):
                    ans[pair[0]][pair[1]] *= 10
                    ans[pair[0]][pair[1]] += -1 * \
                        (index + 1) + (len(word) + 1)
                TRUE_PATH = []


wordsearch(grid, word)
print(*ans, sep="\n")
