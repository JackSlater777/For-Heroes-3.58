# нет подходящей библиотеки, чтобы работать с .pac и .lod архивами

import os
import struct
from zipfile import ZipFile
import io


class Searcher:
    def __init__(self, path):
        self.path = path

    def search_zaobj_txt(self):
        """"""
        print("\n")
        for mod in os.listdir(self.path):
            mod_path = os.path.join(self.path, mod)
            print(mod_path)
            # for file in os.listdir(folder):
            #     fpath = os.path.join(folder, file)

    def loop_archive(self):
        archive_path = r"C:\Users\Иван\Desktop\archive.pac"
        #import shutil
        #shutil.copy(r"C:\Users\Иван\Desktop\archive.pac", r"C:\Users\Иван\Desktop\copy_archive.pac")

        thisFile = r"C:\Users\Иван\Desktop\copy_archive.pac"
        base = os.path.splitext(thisFile)[0]
        os.rename(thisFile, base + ".zip")

        # with open(archive_path, mode="rb") as archive:
        #     print(archive.name)
        #     print(archive)
            # for file in archive:
            #     print("\n")
            #     print(file)

        # ************************************************************************************
        # with ZipFile(archive_path) as zip_archive:
        #     for item in zip_archive.filelist:
        #         print(item)
        #     print(f'\nThere are {len(zip_archive.filelist)} ZipInfo objects present in archive')

        # *************************************************************************************



if __name__ == "__main__":
    mods_path = r"D:\Games\HoMM 3 ERA Daemon\Mods"
    searcher = Searcher(path=mods_path)
    # #searcher.search_zaobj_txt()
    searcher.loop_archive()

    # import sys
    # print(sys.byteorder)  # little
