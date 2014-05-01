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
bool padres;
vector<adn> vutilizados;

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

bool exite(adn *a){

  for(int i=0; i<int(vutilizados.size()); i++){
    
    
    
  }

}

void findADN(adn *actual, string target){

  if(actual->name == target)
    return;
  
  else{
  
    for(int i=0; i<int(vtotal.size()); i++){
      
      if( find(actual->vp.begin(), actual->vp.end(), vtotal[i]) == actual->vp.end() && vtotal[i] != actual->name){
       
        if(changes(actual->name,vtotal[i])){
          //cout<<"Actual: "<<actual->name<<" Siguiente: "<<vtotal[i]<<endl;
          adn *a = new adn();
          a->name = vtotal[i];
          
          //Si el a y el camino hasta llegar a 'a' ya es utilizado, no utilizarlo.
          if(!existe(a)){          
            a->vp = actual->vp;
            a->vpa = actual->vpa;
            a->vp.push_back(actual->name);
            a->vpa.push_back(*actual);
            actual->vh.push_back(vtotal[i]);
            actual->vha.push_back(a);
            vutilizados.push_back(*a);
            //cout<<actual->name<<":"<<a->name<<endl;
            findADN(a,target);
          ç
        }
      }
    }
  }
}


void printHijos(adn *a, string target, string start){
  
  if(padres){
    for(int i=0; i<int(a->vp.size()); ++i){
      //cout<<" "<<a->vp[i]<<endl;
      vfinal[pos].push_back(a->vp[i]);
    }
    padres = false;
  }
  
  vfinal[pos].push_back(a->name);
  if(a->name == target || a->vha.empty()){
    pos++;
    vector<string> v;
    vfinal.push_back(v);
    //vfinal[pos].push_back(start);
    //cout<<a->name<<endl;
    padres = true;
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
  padres = false;
  
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
  //cout<< int(vfinal.size()) <<endl;
  
  vector<vector<string> > vfinal2;
  for(int i=0; i<int(vfinal.size())-1; i++){
    if(vfinal[i][int(vfinal[i].size())-1] == f->name)
      vfinal2.push_back(vfinal[i]);
    /*for(int j=0; j<int(vfinal[i].size()); j++){
      cout<<vfinal[i][j];
      if(j == int(vfinal[i].size())-1)
        cout<<endl;
      else
        cout<<"->";
    }*/
  }
  int max,ind;
  max = 0;
  ind = 0;
  for(int i=0; i<int(vfinal2.size()); i++){
    if(max < int(vfinal2[i].size())){
      max = int(vfinal2[i].size());
      ind = i;
    }
  }
  
  for(int j=0; j<int(vfinal2[ind].size()); j++){
    cout<<vfinal2[ind][j];
    if(j == int(vfinal2[ind].size())-1)
      cout<<endl;
    else
      cout<<"->";
  }
  
  return 0;
  
}


























