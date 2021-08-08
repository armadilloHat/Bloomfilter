#ifndef BLOOM_H__
#define BLOOM_H__

#include <string>
#include <memory>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

struct Song{
  string title;
  string artist;
  double length;
  int id; 
};

struct Playlist {
  int size;
  vector<shared_ptr<Song>> songlist;

};

class Bloom{
public:
  //constructor
  Bloom();
  
  // deconstructor 
  ~Bloom();
  
  int BloomFunc();
  
  //Takes title, artist and length as args and returns pointer to new song object
  shared_ptr<Song>initSong(string title, string artist, double length, int id);
  
  //initializes and returns empty playlist
  shared_ptr<Playlist>initPlaylist();
  
  //Takes pointer to song objects and playlist 
  //Searches bloom filter if match continues without adding song
  // If no match, updates bloom filter and adds song to playlsit
  //returns pointer to playlist
  shared_ptr<Playlist>addSong(shared_ptr<Song> new_song, shared_ptr<Playlist> playlist);

  //Takes song title as key, arraysizeof bit vector and number of hashes to use
  // Will run through 1 2 or 3 independent hashes
  // returns vector of distinctly hashed song names 
  vector<int> BloomHash(string s, int arrSize, int hash_count); 
  
  // takes vector of 1 2 or 3 hashes. Loops through hash buckets and flips bit in 
  // vector to 1
  void BloomFilter(vector<int> hash);
  
  //takes vector of hashes as search key
  // loops through buckets and checks if bit is == 1
  // if match it increments a counter to manage dynamic # of hashes
  // if count > 0 it returns false
  bool SearchBloomFilter(vector<int> hash);


  // bitset<20> bset1;
  int bf_size; 
  int hash_count;
  bitset<20> bset1;
  

private:

};

#endif // Bloom_H__
