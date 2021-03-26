//Mark Zhang - 20 March 2021 - Classes: stores data about movies, music, and video games. User can search catalog for items,
//add items to catalog, delete items from catalog, and quit the program

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movies.h"
#include "Music.h"
#include "VideoGame.h"
#include <vector>

using namespace std;
//Add function gets information from user and uses it to create a new object
void ADD(vector<Media*>* allMedia) {
  char mInput[20];
  cout << "What type of Media would you like to add? (Video Game, Music, Movie) \n";
  cin.get(mInput, 20);
  cin.clear();
  cin.ignore(9999, '\n');
  //Add Video Game
  if (strcmp(mInput, "Video Game") == 0) {
    VideoGame* Game = new VideoGame();
    cout << "Enter Video Game Title \n";
    cin.get(Game -> getTitle(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Year Released \n";
    cin >> *Game -> getYear();
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Publisher \n";
    cin.get(Game -> getPublisher(), 100);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Game Rating \n";
    cin >> *Game -> getRating();
    cin.clear();
    cin.ignore(9999, '\n');
    allMedia -> push_back(Game);
    
  }
  //Add Music
  else if (strcmp(mInput, "Music") == 0) {
    Music* Song = new Music();
    cout << "Enter Music Title \n";
    cin.get(Song -> getTitle(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Music Year; \n";
    cin >> *Song -> getYear(); 
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Music Artist: \n";
    cin.get(Song -> getArtist(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Music Duration: \n";
    cin >> *Song -> getDuration();
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Publisher: \n";
    cin.get(Song -> getPublisher(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    allMedia -> push_back(Song);
    
  }
  //Add Movie
  else if (strcmp(mInput, "Movie") == 0) {
    Movie* movie = new Movie();
    cout << "Enter Movie Title \n";
    cin.get(movie -> getTitle(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Year of Movie: \n";
    cin >> *movie -> getYear();
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Movie Director: \n";
    cin.get(movie-> getDirector(), 50);
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "Enter Movie Duration: \n";
    cin >> *movie -> getDuration();
    cin.clear();
    cin.ignore(9999, '\n');

    cout << "Enter Movie Rating: \n";
    cin >> *movie -> getRating();
    cin.clear();
    cin.ignore(9999, '\n');
    allMedia -> push_back(movie);   
  }
  // Exits back to Home Page if User does not enter valid input
  else {
    cout << "This is not a type of Media. See you back at the home page\n"; 
  }
}
// Search function iterates through vector and prints information based on object found
void SEARCH(vector<Media*>* allMedia) {
  int input;
  char input2[50];
  char input3[50];
  cout << "Would you like to search by TITLE or YEAR? \n";
  //user can choose to search by title or year
  cin.get(input2, 50);
  cin.clear();
  cin.ignore(9999, '\n');
  vector<Media*>:: iterator cycle;

  //if the user chooses to search by title:
  if (strcmp(input2, "TITLE") == 0) {
    cout << "Search for title: \n";
    cin.get(input3, 50);
    cin.clear();
    cin.ignore(9999, '\n');
    //loops until it finds the correct title, then prints information based on media type 
    for (cycle = allMedia -> begin(); cycle != allMedia -> end(); ++cycle) {
      //if title is a video game
      if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 0)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<VideoGame*>(*cycle) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<VideoGame*>(*cycle) -> getRating() << endl << endl;
      }
      //if title is music
      else if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 1)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*cycle) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*cycle) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*cycle) -> getPublisher() << endl << endl;
      }
      //if title is movie
      else if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 2)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*cycle) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movie*>(*cycle) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movie*>(*cycle) -> getRating() << endl << endl;
      }
    }
  }

  //If the user chooses to search by year:     
  else if (strcmp(input2, "YEAR") == 0) {
    cout << "What Year would you like to search by? \n";
    cin >> input;
    cin.clear();
    cin.ignore(9999, '\n');
    //Iterator
    for (cycle = allMedia -> begin(); cycle != allMedia -> end(); ++cycle) {
      //Video Game 
      if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 0)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<VideoGame*>(*cycle) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<VideoGame*>(*cycle) -> getRating() << endl << endl;
      }
      // Music 
      else if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 1)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*cycle) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*cycle) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*cycle) -> getPublisher() << endl << endl;
      }
      //Movie
      else if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 2)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*cycle) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movie*>(*cycle) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movie*>(*cycle) -> getRating() << endl << endl;
      }
    }
  }
  // Asks user to enter valid input
  else {
    "You did not enter a valid input. See you back at the home page \n";
  }
  
}
//Delete Function, based off search function but for deleting the media
void DELETE(vector<Media*>* allMedia) {
  int input;
  char input2[50];
  char input3[50];
  char deletE[50];
  cout << "Would you like to search by TITLE or YEAR? \n";
  cin.get(input2, 50);
  cin.clear();
  cin.ignore(9999, '\n');
  vector<Media*>:: iterator cycle;

  //delete by title
  if (strcmp(input2, "TITLE") == 0) {
    cout << "Delete title: \n";
    cin.get(input3, 50);
    cin.clear();
    cin.ignore(9999, '\n');
    //Prints information before letting the user confirm whether they want to delete
    //3 cases, 1 for each type of media
    for (cycle = allMedia -> begin(); cycle != allMedia -> end(); ++cycle) {
      if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 0)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<VideoGame*>(*cycle) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<VideoGame*>(*cycle) -> getRating() << endl << endl;
	   cout << "Enter yes to confirm that you want to delete, enter any other input to cancel \n"; 
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) { //if user confirms they want to delete
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else { //any other means that the delete operation is cancelled
	cout << "Delete cancelled";
      }
      }
      else if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 1)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*cycle) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*cycle) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*cycle) -> getPublisher() << endl << endl;
	   cout << "Enter yes to confirm that you want to delete, enter any other input to cancel \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Delete cancelled";
      }
      }
      else if ((strcmp(input3, (*cycle) -> getTitle()) == 0) && ((*cycle) -> getType() == 2)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*cycle) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movie*>(*cycle) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movie*>(*cycle) -> getRating() << endl << endl;
	   cout << "Do you wish to delete this Media? Only yes will delete, everything else is taken as no \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Delete cancelled";
      }
      }
    }
    return; 
  }

  //delete by year
  else if (strcmp(input2, "YEAR") == 0) {
    cout << "What Year would you like to search by? \n";
    cin >> input;
    cin.clear();
    cin.ignore(9999, '\n');
    cout << "test";
    for (cycle = allMedia -> begin(); cycle != allMedia -> end(); ++cycle) {
      if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 0)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Publisher: " << dynamic_cast<VideoGame*>(*cycle) -> getPublisher() << endl;
	  cout << "Rating: " << *dynamic_cast<VideoGame*>(*cycle) -> getRating() << endl << endl;
	  cout << "Enter yes to confirm that you want to delete, enter any other input to cancel \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Delete cancelled";
      }
      }
    
      else if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 1)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*cycle) -> getArtist() << endl;
	  cout << "Duration: " << *dynamic_cast<Music*>(*cycle) -> getDuration() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*cycle) -> getPublisher() << endl << endl;
	   cout << "Do you wish to delete this Media? Only yes will delete, everything else is taken as no \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Delete cancelled";
      }
      }
      else if ((input == *(*cycle) -> getYear()) && ((*cycle) -> getType() == 2)) {
	  cout << endl << "Title: " << (*cycle) -> getTitle() << endl;
	  cout << "Year: " << *(*cycle) -> getYear() << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*cycle) -> getDirector() << endl;
	  cout << "Duration: " << *dynamic_cast<Movie*>(*cycle) -> getDuration() << endl;
	  cout << "Rating: " << *dynamic_cast<Movie*>(*cycle) -> getRating() << endl << endl;
	   cout << "Enter yes to confirm that you want to delete, enter any other input to cancel \n";
      cin.get(deletE, 50);
      cin.clear();
      cin.ignore(9999, '\n');
      if (strcmp(deletE, "yes") == 0) {
	delete *cycle;
	cycle = allMedia -> erase(cycle);
	break;

      }
      else {
	cout << "Delete cancelled";
      }
      }

    }
  }
  else {
    cout << "\n You did not enter a valid input";
  }
}    
//short main function for asking the user which of the 3 other functions they would like to use or if they would like to quit
int main() {
  char function[50]; 
  vector<Media*> TotalList;
  bool stillOn = true;
  while (stillOn == true) {
  cout << "\n What would you like to do? ADD, SEARCH, DELETE, QUIT \n";
  cin.get(function, 50);
  cin.clear();
  cin.ignore(9999, '\n');
  if (strcmp(function, "ADD") == 0) {
    ADD(&TotalList);
  }
  else if (strcmp(function, "SEARCH") == 0) {
    SEARCH(&TotalList);
  }
  else if (strcmp(function, "DELETE") == 0) {
    DELETE(&TotalList);
  }
  else if (strcmp(function, "QUIT") == 0) {
    stillOn = false; 
  }
  else {
    cout << "Please give valid input \n";
  }
  
  }
  return 0; 
}
