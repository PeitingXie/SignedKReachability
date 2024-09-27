import os

def read_first_line_of_files(directory):
    # 列出目录中的所有文件
    for filename in sorted(os.listdir(directory), key=lambda x: int(x.split('.')[0])):
        # 检查文件名是否符合 k.txt 格式
        if filename.endswith(".txt") and filename.split('.')[0].isdigit():
            file_path = os.path.join(directory, filename)
            try:
                with open(file_path, 'r', encoding='utf-8') as file:
                    first_line = file.readline().strip()
                    print(f"{filename.split('.')[0]} : {first_line}")
            except Exception as e:
                print(f"无法读取文件 {filename}，错误信息: {e}")

# 使用示例

name = "bitcoinalpha" # folder name
directory_path = "result/"+ name + "/query_time/index"  # 若要online 的信息, 将 index 改成online
# directory_path = "result/"+ name + "/query_time/online"
read_first_line_of_files(directory_path)
