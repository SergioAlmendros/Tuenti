#include <iostream>
#include <vector>

using namespace std;

int len;
pair<char,char> m;
pair<int,int> p; //posicion
/*
  First: '-' HORIZONTAL, '|' VERTICAL
  Second: '<' o '>'
*/

char find(char actual){

  //cout<<actual;
  switch(actual){
    case '-':
      if(m.first == '-' && m.second == '>'){//RIGHT
        actual = '-';
        m.first = actual;
        p.second += 1; 
      }else if(m.first == '-' && m.second == '<'){//LEFT
        actual = '-';
        m.first = actual;
        p.second -= 1 ;
      }else if(m.first == '|' && m.second == '>'){//UP
        actual = '|';
        m.first = actual;
        p.first -= 1;
      }else if(m.first == '|' && m.second == '<'){//DOWN
        actual = '|';
        m.first = actual;
        p.first += 1;
      }else if(m.first == '#'){
        m.first = actual;
        m.second = '>';
        p.second += 1;
      }
      break;
      
    case '\\':
      
      if(m.first == '-' && m.second == '>'){//RIGHT
        m.first = '|';
        m.second = '<';
        p.first += 1;
      }else if(m.first == '-' && m.second == '<'){//LEFT
        m.first = '|';
        m.second = '>';
        p.first -= 1;
      }else if(m.first == '|' && m.second == '>'){//UP
        m.first = '-';
        m.second = '<';
        p.second -= 1; 
      }else if(m.first == '|' && m.second == '<'){//DOWN
        m.first = '-';
        m.second = '>';
        p.second += 1; 
      }
      break;
      
    case '/':
      if(m.first == '-' && m.second == '>'){//RIGHT
        m.first = '|';
        m.second = '>';
        p.first -= 1;
      }else if(m.first == '-' && m.second == '<'){//LEFT
        m.first = '|';
        m.second = '<';
        p.first += 1;
      }else if(m.first == '|' && m.second == '>'){//UP
        m.first = '-';
        m.second = '>';
        p.second += 1; 
      }else if(m.first == '|' && m.second == '<'){//DOWN
        m.first = '-';
        m.second = '<';
        p.second -= 1; 
      }
      break;
    case '#':
      m.first = '#';
      p.second += 1;
      break;
  }
  return actual;
}

int main(){

  string s;
  getline(cin,s);
  //cout<<s<<endl;
  m.first = s[0];
  m.second = '>';
  
  int len = int(s.length());
  char f[2*len][2*len];
  
  int maxi = 0;
  int maxj = 0;
  int mini = 2*len;
  int minj = 2*len;
  
  p.first = len;
  p.second = len+1;
  
  for(int i=0; i<2*len; i++)
    for(int j=0; j<2*len; j++)
      f[i][j] = '.';
  
  for(int i=0; i<int(s.size()); i++){
  
    
   // cout<<m.first<<": ("<<p.first<<","<<p.second<<")"<<endl;
    if(maxi < p.first) maxi = p.first;
    if(maxj < p.second) maxj = p.second;
    
    if(mini > p.first) mini = p.first;
    if(minj > p.second) minj = p.second;
    
    f[p.first][p.second] = find(s[i]);
  }
  
  for(int i=mini; i<=maxi; i++){
    for(int j=minj; j<=maxj; j++)
      if(f[i][j] != '.')
        cout<<f[i][j];
      else
        cout<<' ';
    cout<<endl;
  }
  
  return 0;
}

































