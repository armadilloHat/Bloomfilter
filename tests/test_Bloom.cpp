
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "../code/Bloom.h"

#include <iostream>
#include <string>

using namespace std;

class test_Bloom : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
	}
    
	// this function runs before every TEST_F function
	void SetUp() override {
    }

	// this function runs after every TEST_F function
	void TearDown() override {
	}
};



TEST_F(test_Bloom, TestinitSong){
	Bloom myobj;
	auto song = myobj.initSong("Dancing Queen","Abba",2.37,665);
    ASSERT_EQ("Abba", song->artist );
}


TEST_F(test_Bloom, TestinitaddSong){
	Bloom myobj;
	shared_ptr<Playlist> rock = myobj.initPlaylist();
	// create rock playlist
	myobj.addSong(myobj.initSong("dancing queen", "Abba", 3.2, 1), rock);
	myobj.addSong(myobj.initSong("like rolling stone","Bob Dylan",2.20,12), rock);
	myobj.addSong(myobj.initSong("blowin in the wind","Bob Dylan",2.33,123), rock);
	myobj.addSong(myobj.initSong("visions of johanna","blonde on blonde",4.22,1234), rock);
	myobj.addSong(myobj.initSong("handle with care","traveling wilburys",3.33,12345), rock);
	myobj.addSong(myobj.initSong("going home","under",6.00,123456), rock);
	myobj.addSong(myobj.initSong("forever in love","Crunch man",3.43,6), rock);
	myobj.addSong(myobj.initSong("the moment","Arch",5.32,65), rock);
	myobj.addSong(myobj.initSong("sentimental","Chevelle",2.33,654), rock);

	// w/ false possitives shoudl yield 4;
    ASSERT_EQ(4, rock->size);
	ASSERT_TRUE(rock->songlist[2]);
}



TEST_F(test_Bloom, TestBloomFilter){
    Bloom myBloom;
	shared_ptr<Playlist> now2021 = myBloom.initPlaylist();
	int bf_size = 20;
	int hash_count = 3;

	myBloom.addSong(myBloom.initSong("dancing queen", "Abba", 3.2, 1), now2021);
	myBloom.addSong(myBloom.initSong("Like a Rolling Stone","Bob Dylan",2.20,12), now2021);
	myBloom.addSong(myBloom.initSong("Blowin in the wind","Bob Dylan",2.33,123), now2021);
	myBloom.addSong(myBloom.initSong("visions of johanna","blonde on blonde",4.22,1234), now2021);
	myBloom.addSong(myBloom.initSong("handle with care","traveling wilburys",3.33,12345), now2021);
	myBloom.addSong(myBloom.initSong("going home","Kenny G",6.00,123456), now2021);
	myBloom.addSong(myBloom.initSong("forever in love","Kenny G",3.43,6), now2021);
	myBloom.addSong(myBloom.initSong("the moment","Kenny G",5.32,65), now2021);
	myBloom.addSong(myBloom.initSong("sentimental","Kenny G",2.33,654), now2021);
	
	//update bloom bit vector 
	//will always add items to bloom filter no m
	// for(int i =0; i < now2021->songlist.size(); i++){
	// 	myBloom.BloomFilter((myBloom.BloomHash(now2021->songlist[i]->title, bf_size, hash_count)));
	// }
	//did the bitset get updated?
	ASSERT_TRUE(myBloom.bset1 != NULL);
}


TEST_F(test_Bloom, SearchBloomFilter){
    Bloom myBloom;
	int bf_size = 20;
	int hash_count = 3;
	// check empty bf for song	
	ASSERT_FALSE(myBloom.SearchBloomFilter((myBloom.BloomHash("let it be",bf_size, hash_count))));

	//populate playlist
	myBloom.BloomFilter((myBloom.BloomHash("something you can't see",bf_size, hash_count)));
	cout<< myBloom.bset1[10];
	ASSERT_TRUE(myBloom.SearchBloomFilter((myBloom.BloomHash("something you can't see",bf_size, 2))));
	
	myBloom.BloomFilter((myBloom.BloomHash("robots and stuff",bf_size, hash_count)));
	myBloom.BloomFilter((myBloom.BloomHash("multi love",bf_size, hash_count)));
	myBloom.BloomFilter((myBloom.BloomHash("midnight",bf_size, hash_count)));
	myBloom.BloomFilter((myBloom.BloomHash("don't know why",bf_size, hash_count)));

	// False possitive 
	ASSERT_TRUE(myBloom.SearchBloomFilter((myBloom.BloomHash("why",bf_size, hash_count))));

	

}
