import exceptions
import genres
import id3
import mp3
import shutil

shutil.copyfile("./tests/test.mp3", "./output.mp3")

mp3file = mp3.MP3File("./output.mp3")
mp3file.artist = "stormzy"
mp3file.save()