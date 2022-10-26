#include <Geode/Geode.hpp>
#include <Geode/Modify.hpp>
#include <fstream>
#include <iostream>

USE_GEODE_NAMESPACE();

std::filesystem::path yes = std::filesystem::current_path() / "Resources" / "MenuSongs";

std::string getRandomSong() {
  std::vector<std::string> songs;
    for (auto& p : std::filesystem::directory_iterator(yes)) {
    songs.push_back(p.path().filename().string());
}

  if (songs.size() == 0) {
    return "menuLoop.mp3";
  }

  return "MenuSongs/" + songs[rand() % songs.size()];

}

class $modify(GameSoundManager) {
  void playBackgroundMusic(gd::string song, bool b1, bool b2) {
  
  if (std::string(song) == "menuLoop.mp3")
  song = getRandomSong();
  
  GameSoundManager::playBackgroundMusic(song, b1, b2);
  
  }
};
