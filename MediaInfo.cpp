//
// Created by arthu on 07/11/2020.
//

#include "MediaInfo.h"

MediaInfo::MediaInfo(const std::string mp3file, const std::string outputDir)
: m_Mp3fname(mp3file), m_OutputDir(outputDir) {

}

void MediaInfo::setArtist(const std::string &artist) {
    MediaInfo::m_Artist = artist;
}

void MediaInfo::setName(const std::string &name) {
    MediaInfo::m_Name = name;
}

void MediaInfo::setNr(unsigned int nr) {
    MediaInfo::m_Nr = nr;
}

void MediaInfo::setAlbum(const std::string &album) {
    MediaInfo::m_Album = album;
}

void MediaInfo::writeBack() {
    std::ofstream file(m_TempFile);
    file << "mp3fname=" << m_Mp3fname;
    file << "\nOutputDir=" << m_OutputDir;
    file << "\nName=" << m_Name;
    file << "\nArtist=" << m_Artist;
    file << "\nNr=" << std::to_string(m_Nr);
    file << "\nAlbum=" << m_Album;
    file.close();
}

MediaInfo::~MediaInfo() {
    std::remove(m_TempFile.c_str());
}
