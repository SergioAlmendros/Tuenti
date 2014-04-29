#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pos;

void printVector(vector<string> &v){
  
  for(int i=0; i<int(v.size()); ++i){
    cout<<v[i]<<endl;
  }
}

struct adn{
  string name;
  vector<string> vh;
  vector<adn* > vha;
  vector<string> vp;
  vector<adn> vpa;
};

vector<string> vtotal;
vector<vector<string> > vfinal;

void printVectorADN(vector<adn> &v){
  for(int i=0; i<int(v.size()); ++i){
    cout<<v[i].name<<endl;
  }
}

bool changes(string s, string s2){

  int c=0;
  for(int i=0; i<int(s.length()); ++i){
    if(s[i] == s2[i])
      c++;
  }
  //cout<<s2<<c<<endl;
  if( c == int(s.length()) )
    return false;
  if(c > int(s.length())-2)
    return true;
  else
    return false;
}

void findADN(adn *actual, string target){

  if(actual->name == target)
    return;
  
  else{
  
    for(int i=0; i<int(vtotal.size()); i++){
      
      if( find(actual->vp.begin(), actual->vp.end(), vtotal[i]) == actual->vp.end() && vtotal[i] != actual->name){
       
        if(changes(actual->name,vtotal[i])){
          adn *a = new adn();
          a->name = vtotal[i];
          a->vp = actual->vp;
          a->vpa = actual->vpa;
          a->vp.push_back(actual->name);
          a->vpa.push_back(*actual);
          actual->vh.push_back(vtotal[i]);
          actual->vha.push_back(a);
          //cout<<actual->name<<":"<<a->name<<endl;
          findADN(a,target);
        }
      }
    }
  }
}


void printHijos(adn *a, string target, string start){

  vfinal[pos].push_back(a->name);
  if(a->name == target){
    pos++;
    vector<string> v;
    vfinal.push_back(v);
    vfinal[pos].push_back(start);
  }
  
  for(int i=0; i<int(a->vha.size()); i++){
    printHijos(a->vha[i],target,start);
  }

}

int main(){

  string s,t,a;
  cin>>s;
  cin>>t;
  pos = 0;
  vector<string> v;
  vfinal.push_back(v);
  
  vtotal.push_back(t);
  while(cin>>a){
    if( find(vtotal.begin(),vtotal.end(),a) == vtotal.end() )
      vtotal.push_back(a);
  }
  //cout<<"Source state: "<<s;
  //cout<<" --> Target state: "<<t<<endl;
  //printVector(v);
  
  adn *i = new adn();
  adn *f = new adn();
  i->name = s;
  f->name = t;
  
  findADN(i,f->name);
  
  //printVectorADN(i->vha);
  
  printHijos(i,t,s);
  cout<< int(vfinal.size()) <<endl;
  
  for(int i=0; i<int(vfinal.size()); i++){
    for(int j=0; j<int(vfinal[i].size()); j++){
      cout<<vfinal[i][j];
      if(j == int(vfinal[i].size())-1)
        cout<<endl;
      else
        cout<<"->";
    }
    
  }
  
  return 0;
  
}


























