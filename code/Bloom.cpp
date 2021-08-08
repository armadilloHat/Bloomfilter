#include "Bloom.h"



Bloom::Bloom(){
    shared_ptr<Playlist> playlists;
    shared_ptr<Song> song;
    int bf_size = 20; 
    int hash_count = 3;
}

Bloom::~Bloom(){
    
}

shared_ptr<Song> Bloom::initSong(string title, string artist, double length, int id){
    shared_ptr<Song> new_song(new Song);
    new_song->title = title;
    new_song->artist = artist;
    new_song->length = length;
    new_song->id = id;
    return new_song;  
}

shared_ptr<Playlist> Bloom::initPlaylist(){
    shared_ptr<Playlist> new_playlist(new Playlist);
    new_playlist->size = 0;
    return new_playlist;
}

shared_ptr<Playlist>Bloom::addSong(shared_ptr<Song> new_song, shared_ptr<Playlist> playlist)
{ 
    int hash_count = 3;
    int bf_size = 20;
    if(SearchBloomFilter(BloomHash(new_song->title, bf_size, hash_count)) == true ){
        cout<< "Not Adding: Song may already be in playlist";
    }
    else{
    playlist->songlist.push_back(new_song);
    playlist->size = playlist->size + 1;
    BloomFilter(BloomHash(new_song->title,20,3));
    
    }
    return playlist;
}


vector<int> Bloom::BloomHash(string s, int arrSize, int hash_count){
int hash;
long long int hash1 = 0;
long long int hash2 = 0;
vector<int> hashed;

if(hash_count == 1){
    // single hash function 
    for (int i = 0; i < s.size(); i ++){
        hash1 = hash1 + ((int)s[i]);
        hash1 = hash1 % arrSize;
    }
    hashed.push_back(abs(hash1));
        return hashed;
}
    // independent hash function
else if(hash_count == 2){
    for (int i = 0; i < s.size(); i ++){
        hash1 = hash1 + ((int)s[i]);
        hash1 = hash1 % arrSize;
        hash1 = abs(hash1);
    }
    
    unsigned int hash = 5381;
    for (size_t i=0; i < s.length(); i++) {
        char c = s[i]; 
        hash2 = ((hash2 << 5) + hash) + c;
    }
    hash2 = abs(hash2 % arrSize);
    hashed.push_back(hash1);
    hashed.push_back(hash2);
    return hashed;
    }
else if(hash_count == 3){
    
    // hash 1
    for (int i = 0; i < s.size(); i ++){
        hash1 = hash1 + ((int)s[i]);
        hash1 = hash1 % arrSize;
        hash1 = abs(hash1);

    }
    
    // hash 2
    int hash = 5381;
    for (size_t i=0; i < s.length(); i++) {
        char c = s[i]; 
        hash2 = ((hash2 << 5) + hash) + c;
    }
    hash2 = hash2 % arrSize;
    hash2 = abs(hash2);

    
    // hash 3
    int hash3 = s.length() + 484930;
    hash3 = hash3 % arrSize;
    hash3 = abs(hash3);
    hashed.push_back(hash1);
    hashed.push_back(hash2);
    hashed.push_back(hash3);
    return hashed;
    }
}

//updates bloom filter based on vec
void Bloom::BloomFilter(vector<int> hash){
    for(int i = 0; i < hash.size(); i++){
    bset1[hash[i]] = 1;
    }
}

bool Bloom::SearchBloomFilter(vector<int> hash){
    int counter;
    counter = 0;
    for(int i = 0; i< hash.size(); i++){
        if(bset1[hash[i]] == 1){
            counter = counter + 1;
        }
        else{
            counter = counter + 0;
        }
    }
    if(counter >= 1){
            return true;
        }
    return false;
}
