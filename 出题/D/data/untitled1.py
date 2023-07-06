import os

folder_path = os.getcwd()  # 获取当前工作目录的路径
extension = ".txt"  # 文件后缀名

# 获取文件夹中所有符合条件的文件
files = [file for file in os.listdir(folder_path) if file.endswith(extension)]

# 对文件按照顺序进行重命名
for i, file in enumerate(files):
    old_name = os.path.join(folder_path, file)
    new_name = os.path.join(folder_path, str(i+1) + ".out")
    os.rename(old_name, new_name)
