# 读取新生成的txt文件
with open('baidu/graph.txt', 'r') as file:
    lines = file.readlines()

# 统计总行数和第三个数为负数的行数
total_lines = len(lines)
negative_count = 0

for line in lines:
    # 获取第三个数
    third_num = int(line.split()[2])
    
    # 判断第三个数是否为负数
    if third_num < 0:
        negative_count += 1

# 计算第三个数为负数的比例
negative_ratio = negative_count / total_lines if total_lines > 0 else 0

# 输出结果
print(f"第三个数为负数的比例: {negative_ratio:.2%}")
