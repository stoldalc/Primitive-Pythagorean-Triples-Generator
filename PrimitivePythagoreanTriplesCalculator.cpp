

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 


using namespace std;

//x = 2*s*t
//y = t^2-s^2
//z = t^2-s^2

//Bounds
//t > s
//either s or t is even and the other odd 

void pythTriples(int bound);

void even(int s, int t, int bound);
void odd(int s, int t, int bound);
void printVec();

vector<int> x;
vector<int> y;
vector<int> z;

int main()
{
    
    cout << "**********PROGRAM START**********" << endl;
    int bound;
    cout << "Pythagorean triples in the form of (x,y,z)." << endl;
    cout << "Select a bound for the triples such that x,y,z < bound: ";
    cin >> bound;
    pythTriples(bound);
    cout << "**********PRINTING TRIPLES**********" << endl;
    printVec();
    cout << "**********PROGRAM END**********" << endl;
    

    return 0;
}

void pythTriples(int bound){
    
    even(1,2,bound);
    odd(2,3,bound);
    
}

void even(int s, int t, int bound){
    int xBuff = 2*s*t;
    int yBuff = pow(t,2)-pow(s,2);
    int zBuff = pow(t,2)+pow(s,2);
    
    cout << "Even: (" << xBuff << "," << yBuff << "," << zBuff << ") ";
    cout << " S: " << s << " T: " << t << " GCD(" << s << "," << t << " = " << __gcd(s,t) << ")" << endl;
    
    if(__gcd(s,t) == 1){
    if(xBuff <= bound){
        
        if(yBuff <= bound){
            
            if(zBuff <= bound){
                x.push_back(xBuff);
                y.push_back(yBuff);
                z.push_back(zBuff);
                cout << "added" << endl;
                //Check to make sure that s+2 less then t
                if(s+2 < t){
                    even(s+2,t,bound);
                }else{
                    even(1,t+2,bound);
                }
            }
            else{
                return;
            }
        }
        else{
                return;
            }
    }
    else{
                return;
            }
    }else{
        if(s+2 < t){
                    even(s+2,t,bound);
                }else{
                    even(2,t+2,bound);
                }
    }
}
void odd(int s, int t, int bound){
    int xBuff = 2*s*t;
    int yBuff = pow(t,2)-pow(s,2);
    int zBuff = pow(t,2)+pow(s,2);
    
     cout << "Odd: (" << xBuff << "," << yBuff << "," << zBuff << ")";
     cout << " S: " << s << " T: " << t << " GCD(" << s << "," << t << " = " << __gcd(s,t) << ")" << endl;
    if(__gcd(s,t) == 1){
        
    if(xBuff <= bound){
        
        if(yBuff <= bound){
            
            if(zBuff <= bound){
                x.push_back(xBuff);
                y.push_back(yBuff);
                z.push_back(zBuff);
                if(s+2 < t){
                    odd(s+2,t,bound);
                }else{
                    odd(2,t+2,bound);
                }
                
            }
            else{
                return;
            }
        }
        else{
                return;
            }
    }
    else{
                return;
            }
            
    }else{
        if(s+2 < t){
                    odd(s+2,t,bound);
                }else{
                    odd(2,t+2,bound);
                }
    }       
}

void printVec(){
    for(int i = 0;i < x.size();i++){
        cout << "(" << x[i] << "," << y[i] << "," << z[i] << ")" << endl;
    }
    
    cout << "Number of triples was: " << x.size() << endl;
    
}










