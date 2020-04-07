#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


	class sprawdz
	{
    	ifstream plik1;
    	ofstream plik2;
		public:
        sprawdz();
        ~sprawdz();
	};


//FX-TEAM
	bool isPalindrome(string s)
	{
	        int back = s.length()-1; //ostatnia litera s
	        bool palindrome = true; //zak³adamy ¿e jest
	        for (int i=0; i<s.length()/2 && palindrome; i++) //tylko do po³owy stringu
	                if (s[i] != s[back--]) //back po podstawieniu zmniejszy siê o 1 z ostatniej na przedostatni¹ itd.
	                        palindrome = false;
	                       
	        return palindrome;
	}
/////////


	string word;
	sprawdz::sprawdz()
	{ 
	    plik2.open("wypisz.txt");
    	plik1.open("wprowadz.txt");

     	if(plik1.good())  
        while(!plik1.eof())  
        {
            getline(plik1,word);  
            cout<<word<<"\n";
                   
            string s(word), slowo, polacz("");
			stringstream ss(s);
			while(ss >> slowo) 
			polacz += slowo; 
        	if(isPalindrome(polacz)==1)
			{
				cout<<"\nTo slowo jest palindromem\n";
				plik2<<"[{string: "<<word<<"; palindrom: Tak]";
			}
			else
			{
				cout<<"\nTo slowo nie jest palindromem\n";
				plik2<<"[{string: "<<word<<"; palindrom: Nie}]";
			}
        }
	}
	sprawdz::~sprawdz()
	{ 
	    plik1.close();
	    plik2.close();
	}

int main(int argc, char** argv)
{
	sprawdz x;
} 
