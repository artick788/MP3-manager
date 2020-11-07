//
// Created by arthu on 07/11/2020.
//

#ifndef MP3_MANAGER_MEDIAINFO_H
#define MP3_MANAGER_MEDIAINFO_H

#include <string>
#include <vector>
#include <fstream>

class MediaInfo{
private:
    std::string m_Mp3fname;
    std::string m_OutputDir;
    std::string m_Artist;
    std::string m_Name;
    unsigned int m_Nr;
    std::string m_Album;

    const std::string m_TempFile = "./media_info.temp";

public:
    MediaInfo(const std::string mp3file, const std::string outputDir);

    ~MediaInfo();

    void setArtist(const std::string &artist);

    void setName(const std::string &name);

    void setNr(unsigned int nr);

    void setAlbum(const std::string &album);

    void writeBack();
};


#endif //MP3_MANAGER_MEDIAINFO_H
