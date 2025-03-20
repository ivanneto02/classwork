#include <iostream>
#include <fstream>
using namespace std;


void rCopy(istream &, ostream &);
bool rCopy(const string &, const string &);

int main(int argc, char *argv[]) {

   if (argc != 3) {
      cout << "USAGE: " << argv[0] << " input-file output-file" << endl;
      return 1;
   }

   if (rCopy(argv[1], argv[2])) {
      cout << "Copy completed" << endl;
   } else {
      cout << "Copy not completed" << endl;
   }
   
   return 0;
}



// Implement these functions

void rCopy(istream &in, ostream &out) {

    char c;

    if (in.get(c)) {

        return;
    }

    in >> noskipws >> c;

    if (in.fail()) {

        return;
    }

    rCopy(in, out);

    out << c;

}

bool rCopy(const string &in, const string &out) {
   ifstream fin;
    fin.open(in);
    if(!fin.is_open()){
        cout << "Error opening " << in  << endl;
        return false;
    }


    ofstream fout;
    fout.open(out);
    if(!fout.is_open()){
        cout << "Error opening " << out << endl;
        return false;
    }
   

    rCopy(fin, fout);    

	fin.close();
	fout.close();

   return true;
}
