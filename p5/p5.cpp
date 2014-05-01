#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char a[8][8];

void printGrid(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      cout<<a[i][j];
    }
    cout<<endl;
  }
}
string createString(){
  
  string r = "";
  
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      r += a[i][j];
    }
  }
  return r;
}

bool checkBorders(int i, int j){
  
  if(i < 0 || i > 7 || j < 0 || j > 7)
    return false;
    
  return true; 
  
}

int nb(int i, int j){
  
  int n = 0;
  
  if( checkBorders(i-1,j-1) ){
    if(a[i-1][j-1] == 'X')
      n++;
  }
  if( checkBorders(i-1,j) ){
    if(a[i-1][j] == 'X')
      n++;
  }
  if( checkBorders(i-1,j+1) ){
    if(a[i-1][j+1] == 'X')
      n++;
  }
  if( checkBorders(i,j+1) ){
    if(a[i][j+1] == 'X')
      n++;
  }
  if( checkBorders(i+1,j+1) ){
    if(a[i+1][j+1] == 'X')
      n++;
  }
  if( checkBorders(i+1,j) ){
    if(a[i+1][j] == 'X')
      n++;
  }
  if( checkBorders(i+1,j-1) ){
    if(a[i+1][j-1] == 'X')
      n++;
  }
  if( checkBorders(i,j-1) ){
    if(a[i][j-1] == 'X')
      n++;
  }
  
  return n;  
}

void applyRules(){

  
  int n;
  
  char a2[8][8];
  
  for(int i=0; i<8; i++){
  for(int j=0; j<8; j++){

    n = nb(i,j);
    //cout<<n;
    a2[i][j] = a[i][j];
    
    if( a[i][j] == 'X' ){
      
       if( n < 2 ) a2[i][j] = '-'; // Any live cell with fewer than two live neighbours dies, as if caused by under-population.
       
       if( n == 2 || n == 3 ) a2[i][j] = 'X'; //Any live cell with two or three live neighbours lives on to the next generation.
       
       if( n > 3 ) a2[i][j] = '-'; //Any live cell with more than three live neighbours dies, as if by overcrowding.
      
    }else if(a[i][j] == '-' ){
      
      if( n == 3 ) a2[i][j] = 'X';//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    }
  }
  }
  //printGrid();
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      a[i][j] = a2[i][j];
    }
  }
  //printGrid();
}

int main(){

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      cin>>a[i][j];
    }
  }
  
  //printGrid(a);
  
  int generation = 0;
  bool foundit = false;
  
  vector<string> v;
  v.push_back(createString());
  string s;
  std::vector<string>::iterator it;
  
  //printGrid(); cout<<endl;
  
  while(!foundit && generation != 100){
    //Generar el nuevo grid
    applyRules();
    
    //printGrid(); cout<<endl;
      
    //Crear la string con el nuevo grid
    s = createString();
    //Comprobar que esta string existe en el vector v, si existe se acaba el while
    generation++;
    //cout<<generation<<endl;
    
    if( (it = find(v.begin(),v.end(),s)) != v.end())
      foundit = true;
    else
      v.push_back(s);    
  }
 
  int inicio = find(v.begin(),v.end(),s)-v.begin();
  
  cout<<inicio<<" ";
  cout<<generation-inicio<<endl;

}
























