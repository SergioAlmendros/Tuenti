#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>  

using namespace std;
 

int main(){
  
  int a,b,tests;
  double a2,b2,t;
  string s;
  cin>>tests;
  //cout<<tests<<endl;
  for(int i=0; i<tests; i++){
    cin>>a;
    cin>>b;

    a2 = a*a;
    b2 = b*b;
    t = sqrt(a2+b2);
    stringstream ss(" ");
    ss << fixed << setprecision(2) << t;
    
    getline(ss,s);
    //cout<<s<<endl;
    
    for(int i=0; i<3; i++){
      
      if(s[s.length()-1] == '0')
        s = s.substr(0,s.length()-1);
      else if((s[s.length()-1] == '.'))
        cout<<s.substr(0,s.length()-1)<<endl;
      else{
        cout<<s<<endl;
        break;
      }
    }
    
    
  }
  
}


















