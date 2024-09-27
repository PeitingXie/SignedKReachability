import os

# 定义绝对路径
base_dir = '/data/peitingx/SignedKReachability/result/dbpedia/query_time/scale'
subfolders = ['20', '40', '60', '80', '100']
target_folders = ['index', 'online']

# 遍历每个文件夹并读取6.txt文件
for subfolder in subfolders:
    for target_folder in target_folders:
        file_path = os.path.join(base_dir, subfolder, target_folder, '6.txt')
        
        if os.path.exists(file_path):
            print(f"读取文件: {file_path}")
            print(f"所在数字文件夹: {subfolder}, 所在文件夹: {target_folder}")
            with open(file_path, 'r') as f:
                content = f.read()
                print(content)  # 输出文件内容
        else:
            print(f"文件 {file_path} 不存在")
