import exceptions
import genres
import id3
import mp3
import shutil
import sys

class MediaInfo:
    def __init__(self):
        self.artist = 0
        self.album = 0
        self.name = 0
        self.nr = 0

def removeNewLine(string):
    retVal = ""
    for i in range(len(string)):
        if string[i] == '\n':
            continue
        else:
            retVal += string[i]
    return retVal


def parseNewName(info, outputdir):
    print(info.name)
    retVal = outputdir + info.artist + " - " + info.name + ".mp3"
    return retVal


def addTags(info, newName):
    mp3file = mp3.MP3File(newName)
    mp3file.artist = info.artist
    mp3file.album = info.album
    mp3file.song = info.name
    mp3file.save()


def main():
    file = open("./media_info.temp").readlines()
    info = MediaInfo()
    mp3name = 0
    outputdir = 0
    for line in file:
        sign = line.split('=')
        if sign[0] == "mp3fname":
            mp3name = removeNewLine(sign[1])
        elif sign[0] == "OutputDir":
            outputdir = removeNewLine(sign[1])
        elif sign[0] == "Name":
            info.name = removeNewLine(sign[1])
        elif sign[0] == "Artist":
            info.artist = removeNewLine(sign[1])
        elif sign[0] == "Nr":
            info.nr = removeNewLine(sign[1])
        elif sign[0] == "Album":
            info.album = removeNewLine(sign[1])
    newName = parseNewName(info, outputdir)
    shutil.copyfile(mp3name, newName)
    addTags(info, newName)


main()
