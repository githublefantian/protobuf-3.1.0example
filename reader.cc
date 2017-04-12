#include "lm.helloworld.pb.h" 
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <pthread.h>
#include <fstream>

using namespace std;

void ListMsg(const lm::helloworld & msg) { 
  cout << msg.id() << endl; 
  cout << msg.str() << endl; 
 } 
 
int main(int argc, char* argv[]) { 
  lm::helloworld msg1; 
  {    
    fstream input("./log", ios::in | ios::binary); 
    if (!msg1.ParseFromIstream(&input)) { 
      cerr << "Failed to parse address book." << endl; 
      return -1; 
    } 
  } 
 
  ListMsg(msg1);    
}
