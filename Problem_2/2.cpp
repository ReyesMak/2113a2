#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Search for a word w in a file named fn
// word: word to search for
// fn: name of file to search
// nLines: (output) number of lines w appear in fn
// total: (output) total number of occurrences of w in fn


//Function to find the number of lines {nLines} and the total occurence {total}
int SearchWord(string word, string fn, int &nLines, int &total) {
  ifstream fin;
  //Declare string {line} to read lines and string {element} to read individual words of the file {fn}
  string line, element;
  //Declare integer {last_total} to count for the total number of occurences up until the previous line
  int last_total = 0;
  //Open the file {fn}
  fin.open(fn);
  if (fin.fail()){
    // Return 1 if file operation is unsuccessful
    return 1;
  }
  //Read lines of file {fn} from top to bottom
  while (getline(fin,line)){
    //Create an input string stream object istringstream
    istringstream line_in(line);
    //Assign the total number of occurences of {word} up until the previous line to {last_total}
    last_total = total;
    //Stored strings on each line {line_in} onto {element}
    while (line_in >> element){
      //Convert all letters of {element} to lowercase
      for (int i=0; i<element.length();++i){
        element[i]=tolower(element[i]);
      }
      //Total occurence {total} increments by 1 if found {word}
      if (element==word){
        total++;
     }
    }
    //Number of lines {nLines} increments by 1 if the total occurence of {word} until the line is different from that until the previous line
    if (total != last_total){
      nLines++;
    }
  }
  // Return 0 if file operation is successful
  return 0;
}

int main(int argc, char* argv[])
{
  if (argc < 3) {
    cout << "usage: " << argv[0] << " [word_to_search] [file1] [file2] [file3]...\n";
    exit(1);
  }

  string word = argv[1];  // word to search for

  // loop through all the filenames in the command line argument
  for (int i = 2; i < argc; ++i) {
    string filename = argv[i];
    int lineCount=0, totalCount=0;
    // search word in file
    if (SearchWord(word, filename, lineCount, totalCount))
      cout << filename << ": error opening file" << endl;
    else
      cout << filename << ": " << lineCount << " " << totalCount << endl;
  }

  return 0;

}
