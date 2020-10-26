"""One of the ways to print some directory's content, icluding all subdirectories"""

import os

initial_path = '.' # initial directory

for path, sub_foldes, files in os.walk(start_path):
    print(f"At directory '{path}'\n - subfolders: {sub_foldes}\n - files: {files}\n")
