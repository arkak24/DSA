// BRUTE -> works for both sorted and unsorted
// TC -> O(n1*log(n) + n2*log(n)) + O(n1+n2)
// SC -> O(n1+n2) + O(n1+n2)
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> make_union(vector<int> &vect1, vector<int> &vect2)
// {
//     int a = vect1.size();
//     int b = vect2.size();

//     set<int> st;
//     for (int i = 0; i < a; i++)
//     {
//         st.insert(vect1[i]);
//     }
//     for (int i = 0; i < b; i++)
//     {
//         st.insert(vect2[i]);
//     }
//     vector<int> vec;
//     for (auto iterator : st)
//     {
//         vec.emplace_back(iterator);
//     }
//     return vec;
// }

// int main()
// {

//     vector<int> vec1;
//     vector<int> vec2;

//     int a, b, temp;
//     cout << "Enter the number of elements in the first input: ";
//     cin >> a;
//     cout << "Enter the elements: ";
//     for (int i = 0; i < a; i++)
//     {
//         cin >> temp;
//         vec1.emplace_back(temp);
//     }
//     cout << "Enter the number of elements in the second input: ";
//     cin >> b;
//     cout << "Enter the elements: ";
//     for (int i = 0; i < b; i++)
//     {
//         cin >> temp;
//         vec2.emplace_back(temp);
//     }

//     vector<int> temp_vector = make_union(vec1, vec2);

//     for (int i = 0; i < temp_vector.size(); i++)
//     {
//         cout << temp_vector[i] << " ";
//     }
//     return 0;
// }

// OPTIMAL -> works only if both the arrays are sorted
// assuming both the arrays are sorted
#include<bits/stdc++.h>
using namespace std;

vector<int> union_two(vector<int> &vect1, vector<int> &vect2){
    int n1 = vect1.size();
    int n2 = vect2.size();

    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(vect1[i] <= vect2[j]){
            if(unionArr.size() == 0 || unionArr.back() != vect1[i]){
                unionArr.emplace_back(vect1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != vect2[j]){
                unionArr.emplace_back(vect2[j]);
            }
            j++;
        }
    }
    while(j < n2){
        if(unionArr.size() == 0 || unionArr.back() != vect2[j]){
                unionArr.emplace_back(vect2[j]);
        }
        j++;
    }
    while(i < n1){
        if(unionArr.size() == 0 || unionArr.back() != vect1[i]){
                unionArr.emplace_back(vect1[i]);
        }
        i++;
    }
    return unionArr;
}

int main()
{

    vector<int> vec1;
    vector<int> vec2;

    int a, b, temp;
    cout << "Enter the number of elements in the first input: ";
    cin >> a;
    cout << "Enter the elements: ";
    for (int i = 0; i < a; i++)
    {
        cin >> temp;
        vec1.emplace_back(temp);
    }
    cout << "Enter the number of elements in the second input: ";
    cin >> b;
    cout << "Enter the elements: ";
    for (int i = 0; i < b; i++)
    {
        cin >> temp;
        vec2.emplace_back(temp);
    }

    vector<int> temp_vector = union_two(vec1, vec2);

    for (int i = 0; i < temp_vector.size(); i++)
    {
        cout << temp_vector[i] << " ";
    }
    return 0;
}