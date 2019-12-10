#include <iostream>
#include "MusicDB.h"
#include "Song.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string getUserInput();
void addCommand();
void saveCommand();
void listCommand();
void helpCommand();


struct Song new_song;
string genre;

//Convert genre input to enum
Genre convertStringToGenre(string genre)
{
	Genre return_value;

	transform(genre.begin(), genre.end(), genre.begin(),
		[](unsigned char c) {return tolower(c); });

	if (genre == "blues") {
		return_value = Blues;
	}
	else if (genre == "country") {
		return_value = Country;
	}
	else if (genre == "electronic") {
		return_value = Electronic;
	}
	else if (genre == "folk") {
		return_value = Folk;
	}
	else if (genre == "hiphop") {
		return_value = HipHop;
	}
	else if (genre == "jazz") {
		return_value = Jazz;
	}
	else if (genre == "latin") {
		return_value = Latin;
	}
	else if (genre == "pop") {
		return_value = Pop;
	}
	else if (genre == "rock") {
		return_value = Rock;
	}
	return return_value;
}

//convert Genre enum to word output for user
string convertGenreToSTring(Genre genre)
{
	string return_value;

	switch (genre) {
	case Blues:
		return_value = "Blues";
		break;
	case Country:
		return_value = "Country";
		break;
	case Electronic:
		return_value = "Electronic";
		break;
	case Folk:
		return_value = "Folk";
		break;
	case HipHop:
		return_value = "HipHop";
		break;
	case Jazz:
		return_value = "Jazz";
		break;
	case Latin:
		return_value = "Latin";
		break;
	case Pop:
		return_value = "Pop";
		break;
	case Rock:
		return_value = "Rock";
		break;
	}
	return return_value;
}


int main()
{
	try
	{
		MusicDB::loadDatabase();
	}
	catch (...)
	{
		//these are not the droids you're looking for
	}

	helpCommand();

	bool exit_program = false;

	while (!exit_program)
	{
		string input_option = getUserInput();
		if (input_option == "add")
		{
			addCommand();
		}

		else if (input_option == "list")
		{
			listCommand();
		}

		else if (input_option == "save")
		{
			saveCommand();
		}

		else if (input_option == "help")
		{
			helpCommand();
		}

		else if (input_option == "exit")
		{
			exit_program = true;
		}

		else
		{
			cout << "Invalid option. Type 'help' to see a list of valid options." << endl;
		}
	}
}

string getUserInput()
{
	string input;
	cout << "Enter Option: ";
	getline(cin, input);
	return input;
}

//Menu
void helpCommand()
{
	cout << "--------Music Database Options--------" << endl;
	cout << "add : Add a new song to the database" << endl;
	cout << "list : List the songs in the database" << endl;
	cout << "save : Save the songs to the database" << endl;
	cout << "help : Display a menu explaining the commands to the users" << endl;
	cout << "exit : Exit the program" << endl;
}

void listCommand()
{
	int total_songs = MusicDB::getTotalSongsInDatabase();
	cout << "There are " << total_songs << " songs in the database." << endl;
	for (int idx = 0; idx < total_songs; idx++)
	{
		Song song = MusicDB::getSongAtIndex(idx);

		cout << "Title: " << song.title << endl;
		cout << "Artist: " << song.artist << endl;
		cout << "Album: " << song.album << endl;
		cout << "Track: " << song.track_number << endl;
		cout << "Release Year: " << song.release_year << endl;
		cout << "Genre: " << convertGenreToSTring(song.genre) << endl;
		cout << endl;
	}
}

void saveCommand()
{
MusicDB::saveDatabase();
cout << "Song(s) saved." << endl;
}

void addCommand()
{
	Song new_song;
	//Get song info from user
	cout << "Enter the Song Title: ";
	cin.getline(new_song.title, MAX_CHARS_PER_TITLE);
	cout << "Enter the Artist Name: ";
	cin.getline(new_song.artist, MAX_CHARS_PER_ARTIST);
	cout << "Enter the Album Name: ";
	cin.getline(new_song.album, MAX_CHARS_PER_ALBUM);
	cout << "Enter the Track Number: ";
	cin >> new_song.track_number;
	cout << "Enter the Release Year: ";
	cin >> new_song.release_year;
	string genre;
	cout << "Enter the Genre: ";
	cin.ignore();
	getline(cin, genre);
	new_song.genre = convertStringToGenre(genre);
	MusicDB::addSongToDatabase(new_song);
	cout << endl;
}