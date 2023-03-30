////
//// Created by Vahe Aleksanyan on 29.03.23.
////
//#include "iostream"
////#include <bits/stdc++.h>
//using namespace std;
//using namespace std::chrono;
//
//void cout_arr(int a[],int n){
//    for(int i=0;i<n;i++){
//        cout<<"\t"<<a[i];
//        if(i==n-1){
//            cout<<endl;
//        }
//    }
//}
//
//void cout_r(int r[],int n){
//    for(int i=0;i<n;i++){
//        cout<<"\t"<<r[i];
//        if(i==n-1){
//            cout<<endl;
//        }
//    }
//}
//
//void cout_s(int r[],int n){
//    for(int i=0;i<n;i++){
//        int x = i > 0 ? r[i]+1 : 0;
//        cout<<"\t"<<x;
//        if(i==n-1){
//            cout<<endl;
//        }
//    }
//}
//
//// Naive Simple Approach
//int CUT_ROD(int p[],int n){
//    if(n <= 0){
//        return 0;
//    }
//    int q = INT_MIN;
//    for(int i=0;i<n;i++){
//        q = max(q,p[i] + CUT_ROD(p,n-i-1));
//    }
//    return q;
//}
//
//int MEMOIZED_CUT_ROD_AUX(int p[],int n,int r[]){
//    if(r[n] >= 0){ return r[n]; }
//    int q;
//    if(n == 0){ q = 0; }
//    else{
//        q = INT_MIN;
//        for(int i=0;i<n;i++){
//            q = max(q,p[i] + MEMOIZED_CUT_ROD_AUX(p,n-i-1,r));
//        }
//    }
//    r[n] = q;
//    return q;
//}
//
//int MEMOIZED_CUT_ROD(int p[],int n){
//    int r[n+1];
//    for(int i = 0;i<n+1;i++){
//        r[i] = INT_MIN;
//    }
//    return MEMOIZED_CUT_ROD_AUX(p,n,r);
//}
//
//int BOTTOM_UP_CUT_ROD(int p[],int n){
//    int r[n+1];
//    int q;
//    r[0] = 0;
//    for (int j = 1; j <= n; j++)
//    {
//        q = INT_MIN;
//        for (int i = 0; i < j; i++)
//        {
//            q = max(q,p[i]+r[j-i-1]);
//        }
//        r[j] = q;
//    }
//    return r[n];
//}
//
//int Extended_Bottom_Up_Cut_Rod(int p[],int n,int r[],int s[]){
//    int q;
//    r[0] = 0;s[0] = 0;
//    for (int j = 1; j < n+1; j++)
//    {
//        q = INT_MIN;
//        for (int i = 0; i < j; i++)
//        {
//            if(q < (p[i] + r[j-i-1])){
//                q = p[i] + r[j-i-1];
//                s[j] = i;
//            }
//        }
//        r[j] = q;
//    }
//    return q;
//}
//
//void Print_Cut_Rod_Soution(int s[],int n,int r[]){
//    int j = n-1;
//    while(j > 0){
//        cout<<"cut(s) : "<<s[j]<<", max obtainable profit is "<<r[s[j]]<<endl;
//        j = j - s[n-1];
//    }
//}
//
//int MODIFIED_CUT_ROD_AUX(int p[],int n,int r[],int s[]){
//    int q;
//    if(r[n] > 0){ return r[n]; }
//    if(n == 0) { q = 0; }
//    else{
//        q = INT_MIN;
//        for (int i = 0; i < n; i++)
//        {
//            int val = MODIFIED_CUT_ROD_AUX(p,n-i-1,r,s);
//            if(q < (p[i] + val)){
//                q = p[i] + val;
//                s[n] = i;
//            }
//        }
//    }
//    r[n] = q;
//    return q;
//}
//
//int MODIFIED_CUT_ROD(int p[],int n){
//    int r[n+1];int s[n+1];
//    for (int i = 0; i < n+1; i++){
//        r[i] = INT_MIN;
//    }
//    auto start = high_resolution_clock::now();
//    int val = MODIFIED_CUT_ROD_AUX(p,n,r,s);
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout<<"Using MODIFIED_CUT_ROD function, Maximum Obtainable Revenue is "<<val<<" and the cuts are at: "<<endl;
//    int j = n;
//    while (j > 0){
//        cout<<"length of "<<s[j]<<", price is $"<<r[s[j]]<<endl;
//        j = j - s[n];
//    }
//    cout << "Time taken function: "<< duration.count() << " microseconds" << endl<<endl;
//
//}
//
//
//
//int main(int argc, char const *argv[])
//{
//    int p[] = {1,3,5,5, 7,8,8,9};
//    int n = 8;
//    cout<<"For n = "<<n<<endl;
//
//    auto start = high_resolution_clock::now();
//    int result = CUT_ROD(p,n);
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout<<"Using Naive CUT_ROD function, Maximum Obtainable Revenue is "<<result<<endl;
//    cout << "Time taken function: "<< duration.count() << " microseconds" << endl<<endl;
//
//    start = high_resolution_clock::now();
//    result = MEMOIZED_CUT_ROD(p,n);
//    stop = high_resolution_clock::now();
//    duration = duration_cast<microseconds>(stop - start);
//    cout<<"Using MEMOIZED_CUT_ROD function, Maximum Obtainable Revenue is "<<result<<endl;
//    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl<<endl;
//
//    start = high_resolution_clock::now();
//    result = BOTTOM_UP_CUT_ROD(p,n);
//    stop = high_resolution_clock::now();
//    duration = duration_cast<microseconds>(stop - start);
//    cout<<"Using BOTTOM_UP_CUT_ROD function, Maximum Obtainable Revenue is "<<result<<endl;
//    cout << "Time taken function: "<< duration.count() << " microseconds" << endl<<endl;
//
//
//
//    int r[n+1];
//    int s[n+1];
//    start = high_resolution_clock::now();
//    int ebucr_r = Extended_Bottom_Up_Cut_Rod(p,n,r,s);
//    stop = high_resolution_clock::now();
//    duration = duration_cast<microseconds>(stop - start);
//    cout<<"Using Extended_Bottom_Up_Cut_Rod, Maximum Obtainable Revenue is "<<ebucr_r<<endl;
//    cout<<"i"<<endl;
//    for(int i=0;i<=n;i++){
//        cout<<"\t"<<i;
//        if(i == n){
//            cout<<endl;
//        }
//    }
//    cout<<"Prices"<<endl;
//    cout<<"\t0";
//    for(int i=0;i<n;i++){
//        cout<<"\t"<<p[i];
//        if(i==n-1){
//            cout<<endl;
//        }
//    }
//    cout<<"Revenues"<<endl;
//    cout_r(r,n+1);
//    cout<<"Cuts"<<endl;
//    cout_s(s,n+1);
//    Print_Cut_Rod_Soution(s,n+1,r);
//    cout << "Time taken function: "<< duration.count() << " microseconds" << endl<<endl;
//
//    MODIFIED_CUT_ROD(p,n);
//
//    return 0;
//}
