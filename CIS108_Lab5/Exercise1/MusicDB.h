#pragma once
#include "Song.h"
#include <vector>

namespace MusicDB
{
	//Functions that allow user to interact with MusicDB

	//Add a new song to the database
	void addSongToDatabase(Song song);

	//List how many songs are in the database
	int getTotalSongsInDatabase();

	//Get a song at a specific location in the Music Database
	Song getSongAtIndex(int index);

	//Load database
	void loadDatabase();

	//Save database
	void saveDatabase();
}