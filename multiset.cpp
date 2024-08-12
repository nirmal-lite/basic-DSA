#include <iostream>
#include <set>
using namespace std;
//e- erase , i - insert , f- find(), c-count()    -----CEIF------
int main() {
        multiset<int> mn;
        mn.insert(0);
        mn.insert(1);
        mn.insert(5);
        mn.insert(66);
        mn.insert(0);
        mn.insert(1);

        for ( int i : mn){
                cout<<i<<" ";
        }
        cout<<endl;
        auto it=mn.find(4);
        if(it!=mn.end()){
                cout<<*it<<endl;
        }
        mn.erase(5);
        for ( int i : mn){
                cout<<i<<" ";
        }
        cout<<endl;
        mn.erase(mn.find(0));//onlu first occurrence get deleted
        for ( int i : mn){
                cout<<i<<" ";
        }
        cout<<endl;
        auto en=--mn.end();
        cout<<*mn.begin()<<" "<<*++mn.begin()<<" "<<*en<<" "<<*(--en);// cannot do random access


}




















// #include <iostream>
// #include <set>

// int main() {
//     std::multiset<int> ms;

//     ms.insert(5);
//     ms.insert(3);
//     ms.insert(8);
//     ms.insert(5);
//     ms.insert(1);

//     // Traversing the multiset
//     for (auto it = ms.begin(); it != ms.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     // Count of an element
//     std::cout << "Count of 5: " << ms.count(5) << std::endl;

//     // Finding an element
//     auto it = ms.find(3);
//     if (it != ms.end()) {
//         std::cout << "Found element: " << *it << std::endl;
//     }

//     // Erasing an element
//     ms.erase(5);  // Removes all instances of 5

//     // Traversing after erasure
//     for (auto it = ms.begin(); it != ms.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }
