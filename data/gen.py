import random

# 读取txt文件
with open('higgs-social_network.txt', 'r') as file:
    lines = file.readlines()

# 处理每一行
new_lines = []
for line in lines:
    a, b = map(int, line.split())
    
    # 根据概率生成-1或1
    random_num = random.choices([-1, 1], weights=[30, 70], k=1)[0]
    
    # 将新的数添加到每一行
    new_lines.append(f"{a} {b} {random_num}\n")

# 将结果写入一个新的txt文件
mkdir higgs-social_network
with open('higgs-social_network/graph.txt', 'w') as file:
    file.writelines(new_lines)

print("处理完成，新数据已保存到new_data.txt")
