#include<bits/stdc++.h>
using namespace std;

void migratoryBirds(vector<int> arr) {
    set<int>s1;
    for(auto i: arr) s1.insert(i);
    for
}
int main(){
      vector<int>v1={1 ,4 ,4 ,4 ,5 ,3};
      migratoryBirds(v1);
      return 0;
}

// def migratoryBirds(arr):
//     # Write your code here
//     id_ar=list(set(arr))
//     id_ar.sort()
//     counter=[]
//     for i in range(len(id_ar)):
//         counter.append(arr.count(id_ar[i]))
//     return(id_ar[counter.index(max(counter))])



// def migratoryBirds(arr):
//     lst=list(set(arr))
//     m=0
//     for i in lst:
//         if m<arr.count(i):
//             up=i
//             m=arr.count(i)
//     return up