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


int main(void) 
 { 
  
  lm::helloworld msg1; 
  msg1.set_id(101);
  msg1.set_str("hello"); 
    
  // Write the new address book back to disk. 
  fstream output("./log", ios::out | ios::trunc | ios::binary); 
        
  if (!msg1.SerializeToOstream(&output)) { 
      cerr << "Failed to write msg." << endl; 
      return -1; 
  }         
  return 0; 
 }
