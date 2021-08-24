#include <iostream>
#include <fstream>
using namespace std;

class saveOutput
{
private:
    streambuf *outPut;

public:
    saveOutput(ofstream &file) : outPut{file.rdbuf()}
    {
        cout.rdbuf(outPut);
        cout<<"hmadarchod";
    }
};

int main()
{
    ofstream file("file.txt");
    saveOutput savefile(file);
    return 0;
}


/*
{
fstream file; 
    file.open("cout.txt", ios::out); 
    string line; 
  
    // Backup streambuffers of  cout 
    streambuf* stream_buffer_cout = cout.rdbuf(); 
    streambuf* stream_buffer_cin = cin.rdbuf(); 
  
    // Get the streambuffer of the file 
    streambuf* stream_buffer_file = file.rdbuf(); 
  
    // Redirect cout to file 
    cout.rdbuf(stream_buffer_file); 
  
    cout << "This line written to file" << endl; 
  
    // Redirect cout back to screen 
    cout.rdbuf(stream_buffer_cout); 
    cout << "This line is written to screen" << endl; 
  
    file.close();
}
*/