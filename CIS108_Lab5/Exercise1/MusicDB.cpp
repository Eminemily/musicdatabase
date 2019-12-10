#include "MusicDB.h"
#include <stdexcept>
#include <fstream>
#include "song.h"

using namespace std;
namespace MusicDB

{
	vector<Song> songDatabase;
	const string databaseFilename = "music.db";

	//Add a new song to the database
	void addSongToDatabase(Song song)
	{
		songDatabase.push_back(song);
	}
	//List how many songs are in the database
	int getTotalSongsInDatabase()
	{
		return songDatabase.size();
	}
	//Get a song at a specific location in the Music Database
	Song getSongAtIndex(int index)
	{
		if (index < getTotalSongsInDatabase())
		{
			return songDatabase[index];
		}
		else
		{
			throw new out_of_range("Invalid index into Music Database.");
		}
	}

		//Load database
		void loadDatabase()
		{
			ifstream file(databaseFilename, ios::binary);

			int count = 0;
			file >> count;

			for (int x = 0; x < count; x++)
			{
				Song song;
				file.read((char*)& song, sizeof(Song));
				songDatabase.push_back(song);
			}
			file.close();
		}

		//Save database
		void saveDatabase()
		{
			ofstream file(databaseFilename, ios_base::trunc | ios_base::binary);
			file << getTotalSongsInDatabase();

			auto itr = songDatabase.begin();
			while (itr != songDatabase.end())
			{
				Song song = *itr;
				file.write((const char*)&song, sizeof(Song));
				itr++;
			}
			file.close();
		}
	}
