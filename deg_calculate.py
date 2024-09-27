# 处理有向符号图
def process_directed_symbol_graph(file_path):
    # 初始化统计信息
    positive_edges = 0
    negative_edges = 0
    degree_positive = {}
    degree_negative = {}

    # 读取文件
    with open(file_path, 'r') as file:
        for line in file:
            u, v, sign = line.strip().split()
            u, v = int(u), int(v)
            sign = int(sign)
            
            if sign > 0:
                positive_edges += 1
                # 统计正边的度数
                degree_positive[u] = degree_positive.get(u, 0) + 1  # u的出度
                degree_positive[v] = degree_positive.get(v, 0) + 1  # v的入度
            elif sign < 0:
                negative_edges += 1
                # 统计负边的度数
                degree_negative[u] = degree_negative.get(u, 0) + 1  # u的出度
                degree_negative[v] = degree_negative.get(v, 0) + 1  # v的入度

    # 计算最大度数
    max_deg_pos = max(degree_positive.values(), default=0)
    max_deg_neg = max(degree_negative.values(), default=0)
    
    # 输出结果
    print(f"正边数量: {positive_edges}")
    print(f"负边数量: {negative_edges}")
    print(f"正边最大度数: {max_deg_pos}")
    print(f"负边最大度数: {max_deg_neg}")

# 使用示例
process_directed_symbol_graph('data/higgs-social_network/graph.txt')
