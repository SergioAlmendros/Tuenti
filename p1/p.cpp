#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct student {
  string gender;
  string age;
  string studies;
  string year;
};

struct studentComplete {
  string name;
  string gender;
  string age;
  string studies;
  string year;
};

void printVector(vector<student> &v){

  for(int i=0; i<int(v.size()); i++){
    cout<<v[i].gender<<"-";
    cout<<v[i].age<<"-";
    cout<<v[i].studies<<"-";
    cout<<v[i].year;
    cout<<endl;
  }
}

void printVectorC(vector<studentComplete> &v){

  for(int i=0; i<int(v.size()); i++){
    cout<<v[i].name<<"-";
    cout<<v[i].gender<<"-";
    cout<<v[i].age<<"-";
    cout<<v[i].studies<<"-";
    cout<<v[i].year;
    cout<<endl;
  }
}

void readFile(vector<studentComplete> &vc){

  int c = 0;
  ifstream is;
  string s,s2;
  is.open("students",ifstream::in);
  while(getline(is,s)){
    //cout<<s<<endl;
    stringstream ss(s);
    studentComplete st;
    while(getline(ss,s2,',')){
      //cout<<" "<<s2;
      if( c == 0 )
        st.name = s2;
      else if( c == 1 )
        st.gender = s2;
      else if( c == 2 )
        st.age = s2;
      else if( c == 3 )
        st.studies = s2;
      else if( c == 4 ){
        st.year = s2; 
        c = -1; 
        vc.push_back(st);
      }
      c++;
    }
  }
  is.close();

}

int main(){

  string s,s2;
  int t; cin >> t;
  int c = 1;
  int i=-1;
  vector<studentComplete> vc;
  vector<string> vf;
  readFile(vc);
  
  while(getline(cin,s)){
    //cout<<s<<endl;
    if(i>=0){
      stringstream ss(s);
      student st;
      while(getline(ss,s2,',')){
        //cout<<" "<<s2;
        if( c == 1 )
          st.gender = s2;
        else if( c == 2 )
          st.age = s2;
        else if( c == 3 )
          st.studies = s2;
        else if( c == 4 ){
          st.year = s2; 
          c = 0; 
        }
          
        c++;
      }
      //cout<<endl;

      for(int j=0; j<int(vc.size()); j++){
        if( st.gender == vc[j].gender && st.age == vc[j].age && st.studies == vc[j].studies && st.year == vc[j].year )
          vf.push_back(vc[j].name);      
      }
      
      sort(vf.begin(),vf.end());
      
      cout<<"Case #"<<i+1<<": ";
      if(vf.empty()){
         cout<<"NONE"<<endl;
      }else{
        for(int k=0;k<int(vf.size());k++){
          cout<<vf[k];
          if(k<int(vf.size())-1)
            cout<<",";
        }
        cout<<endl;
      }
      vf.clear();
    }
    i++;
  }
  //cout<<int(v.size())<<endl;
  //printVector(v);


  
  
    

}































