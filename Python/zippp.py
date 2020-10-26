#!/usr/bin/env python
import os
import zipfile

# input directory file/folder yg akan di zip
dirPath = '/home/user/myfolder'

# input name zip
Zipname = 'myfolder.zip'


def zipfunc(path, ziph):
    for root, dirs, files in os.walk(path):
        for file in files:
            ziph.write(os.path.join(root, file))


if __name__ == '__main__':
    zipf = zipfile.ZipFile(Zipname, 'w', zipfile.ZIP_DEFLATED)
    zipfunc(dirPath, zipf)
    zipf.close()
