#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
// for equal type 'less_equal'

#define ll long long
#define int long long
#define nl '\n'
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(a) a.begin(),a.end()
#define flush fflush(stdout) 
const long long INF = 1e18;
#define check cout<<"ok"<<nl
#define printVec(v) for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<nl
#define printVecPair(v) for(auto it : v){cout<<it.first<<" "<<it.second<<nl;}
// bool cmp(pair<int,int> &a, pair<int,int> &b){return a.second < b.second;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x>>k)&1)
const int mod = 998244353;
const int N  = 2e5+5;

struct node{
    int val;
    node* next;

    node(int data){
        val = data;
        next = NULL;
    }

    node(int data, node* next1){
        val = data;
        next = next1;
    }
};

node* convert(vector<int> &v){
    node* head = new node(v[0]);
    node* mover = head;

    for(int i=1;i<v.size();i++){
        node* temp = new node(v[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

node* remvoe_head(node* head){
    node * temp = head;
    if(head == NULL){
        return head;
    }

    head = head->next;

    delete temp;

    return head;
}

node* remove_tail(node* head){
    if(head == NULL){
        cout<<"Linked list is empty"<<nl;
        return head;
    }
    if(head->next == NULL){
        return NULL;
    }
    node * temp = head;
    while(head->next->next != NULL){
        head = head->next;
    }

    delete head->next;
    head->next = NULL;

    return temp;


}

node* insert(node* head, int data,int pos){

    if(head == NULL){
        if(pos == 1){
            return new node(data);
        }
        else return head;
    }
    else if(pos == 1){
        return new node(data,head);
    }
    else{
        int ct = 0;
        node* temp = head;

        while(temp != NULL){
            ct++;
            if(ct  ==  pos-1){
                node* x = new node(data,temp->next);
                temp->next = x;
                return head;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
}

void solve(){
    vector<int> v = {2,4,2,3,5};

    node* head = convert(v);
    head = insert(head,7,8);
    node* mover = head;

    while(mover != NULL){
        cout<<mover->val<<nl;
        mover = mover->next;
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _t = 1;
    // cin>>_t;
    for(int i = 1;i<=_t;i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
}
