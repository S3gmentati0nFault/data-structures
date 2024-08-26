def check_coloring():
    path = "../testing-files/"

    graph_file = open(path + "graph.txt", "r")
    coloring_file = open(path + "coloring.txt", "r")
    length = 0
    i = 0
    adj_matrix = [];

    # Build matrix from file
    for line in graph_file:
        if i == 0:
            length = int(line)
        else:
            prep_line = file_preprocessing(line)
            adj_line = []
            for j in range(0, length):
                if j in prep_line:
                    adj_line.insert(j, 1)
                else:
                    adj_line.insert(j, 0)
            adj_matrix.append(adj_line)
        i = i + 1

    #print(adj_matrix)
    #print("\n\n\n")


    # Build coloring from file
    for line in coloring_file:
        prep_coloring = file_preprocessing(line)
        #print(prep_coloring);


    # Check the coloring
    for i in range(0, length):
        current_color = prep_coloring[i]
        for j in range(0, length):
            if adj_matrix[i][j] == 1 and prep_coloring[j] == current_color and i != j:
                print(f"Il nodo {j} e il nodo {i} hanno lo stesso colore e sono vicini\n")


    graph_file.close()
    coloring_file.close()


def file_preprocessing(line):
    split_line = line.split(",")
    split_line.remove("\n")
    for j in range(0, len(split_line)):
        split_line[j] = int(split_line[j])
    return split_line


check_coloring()
