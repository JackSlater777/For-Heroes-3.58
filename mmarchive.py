import os
import zipfile
import struct

MMARCHIVE_PATH = r"D:\Games\HoMM 3 ERA Daemon stable\Tools\MMArchive\MMArchive.exe"
ARCHIVE_PATH = r"D:\Games\HoMM 3 ERA Daemon stable\Mods\WoG Fix Rus + Emerald Artifacts\Data\WF_OB_txt.pac"
# ARCHIVE_PATH = r"D:\Games\HoMM 3 ERA Daemon stable\Mods\WoG Fix Rus + Emerald Artifacts\Data\WF_lng.pac"


def read_archive(path: str):
    # with open(path, "rb") as f:
    #     binary_data = f.read(13)
    #     print(5)
    #     s = struct.Struct('@ 3s 10x')
    #     a, b = s.unpack_from(binary_data, 0)
    #     print(5)

    with zipfile.ZipFile(file=path, mode='r', compression=zipfile.ZIP_DEFLATED) as zf:
        for file in zf.infolist():
            name = os.path.basename(file.filename)
            print(5)


if __name__ == "__main__":
    # os.startfile(MMARCHIVE_PATH)
    read_archive(path=ARCHIVE_PATH)
