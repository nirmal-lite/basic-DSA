
#include<bits/stdc++.h>
using namespace std;
class base{
        public:
        base(){
                cout<<"base constr\n";
        }
        ~ base(){
                cout<<"base destructor\n";
        }
        // virtual ~ base(){
        //         cout<<"base destructor\n";
        // }
        
};
class derived:public base{
      public:
      derived(){
        cout<<"derived constr\n";

      }
       ~derived(){
        cout<<"derived distructor\n";
      }
};
int main(){


        derived * b= new derived();
        delete b;
        // base * b= new derived();
        // delete b;
        
}

