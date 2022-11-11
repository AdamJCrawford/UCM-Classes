class Node:
    def __init__(self, index, key=2147483647, parent=None, pairs=None):
        self.index = index
        self.key = key
        self.parent = parent
        self.pairs = pairs


checked = [0] * 9


def min_span_tree():
    nodes[0].key = 0
    q = nodes[:]
    while q:
        u = q[0]
        q = q[1:]
        # if checked[u.index]:
        #     continue

        if u.pairs:
            for pair in u.pairs:
                if pair:
                    if checked[pair[0]]:
                        continue
                    if nodes[pair[0]].key > pair[1]:
                        nodes[pair[0]].parent = u
                        nodes[pair[0]].key = pair[1]
                        q.append(nodes[pair[0]])
                        checked[u.index] = 1
        q = sorted(q, key=lambda x: x.key)
        # input()


nodes = [Node(i) for i in range(9)]

nodes[0].pairs = [[1, 13], [7, 6]]  # Done
nodes[1].pairs = [[0, 13], [2, 1], [7, 12]]  # Done
nodes[2].pairs = [[1, 1], [3, 10], [5, 5], [8, 7]]  # Done
nodes[3].pairs = [[2, 10], [4, 4], [5, 11]]  # Done
nodes[4].pairs = [[3, 4], [5, 3]]  # Done
nodes[5].pairs = [[2, 5], [3, 11], [4, 3], [6, 2]]  # Done
nodes[6].pairs = [[5, 2], [7, 8], [8, 14]]  # Done
nodes[7].pairs = [[0, 6], [1, 12], [6, 8], [8, 9]]  # Done
nodes[8].pairs = [[2, 7], [6, 14], [7, 9]]  # Done

for i in range(9):
    if nodes[i].pairs:
        nodes[i].pairs = sorted(nodes[i].pairs, key=lambda x: x[1])
min_span_tree()
for node in nodes[1:]:
    if node.parent:
        print(node.parent.index)
    else:
        print(-1)
