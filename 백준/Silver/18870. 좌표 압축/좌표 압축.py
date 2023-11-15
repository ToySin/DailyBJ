def pos_zip(pos_list):
    sorted_list = list(sorted(set(pos_list)))
    rank_dict = {sorted_list[i]: i for i in range(len(sorted_list))}

    for pos in pos_list:
        print(rank_dict[pos], end=' ')



n = int(input())

num_list = list(map(int, input().split(' ')))

pos_zip(num_list)