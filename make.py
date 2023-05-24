import os
import subprocess
import sys
import threading

CXX = "g++"
CXX_FLAGS = "-g -O2 -Iinclude --std=c++17 -c"

subprocess.run("rm -rf bin", shell=True)
os.mkdir("bin")

task_list = []

def get_dir_tasks(dir):
    for file in os.listdir(dir):
        if os.path.isdir(f"{dir}/{file}"):
            get_dir_tasks(f"{dir}/{file}")
        else:
            if file.split(".")[-1] == "cpp":
                task_list.append(f"{dir}/{file}")

get_dir_tasks(".")

def process_task(task):
    subprocess.run(f"{CXX} {CXX_FLAGS} {task} -o bin/{task.replace('/', '_').replace('._src_', '').replace('.cpp', '.o')}", shell=True)
    print(f"[CXX] {task}")

def worker(thread_num):
    while True:
        if thread_num >= len(task_list):
            break
        task = task_list[thread_num]
        process_task(task)
        thread_num += os.cpu_count()

threads = []
for i in range(os.cpu_count()):
    thread = threading.Thread(target=worker, args=(i,))
    thread.start()
    threads.append(thread)

for thread in threads:
    thread.join()

if sys.platform == "win32":
    subprocess.run(f"{CXX} -O2 -g bin/*.o -o midnight.exe -lraylib -lopengl32 -lws2_32 -lgdi32 -lImagehlp -lwinmm -DPLATFORM_DESKTOP", shell=True)
    print("[LD] midnight.exe")