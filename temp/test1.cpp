#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    // char data[100];   
    // std::ifstream readFile;
    // readFile.open("1.txt");
    // int cnt = 0;
    char data[100];
	ifstream in("map/map1.txt");
	while(!in.eof()){
        in.getline(data, 100);
        cout<<data<<endl;
	}
	in.close();
    
    
    // if(readFile.is_open()){
    //     while (!readFile.eof()){
    //         readFile.getline(data, 100);
    //         cnt++;
    //     }
    // }

    
//     for(int i=0;i<5;i++){
//         cout<<data[i];
//     }
    
    return 0;
}