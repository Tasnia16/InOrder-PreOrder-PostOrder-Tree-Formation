#include<bits/stdc++.h>
using namespace std;
string tree[100];
int maxi;
void root(string key)
{
    if(!tree[1].empty())
        cout<<"Tree already had root :";
    else
        tree[1]=key;
}
void print_tree()
{
    int i;
    for(i=1;i<maxi+1;i++)
    {
        if(tree[i].empty())
            cout<<"-"<<" ";
        else
            cout<<tree[i]<<" ";
    }
}
void set_left(string key,int parent)
{
    if(tree[parent].empty())
        cout<<"Can't set child at" << (parent*2)<<" ";
    else
        tree[(parent*2)]=key;
}
void set_right(string key,int parent)
{
    if(tree[parent].empty())
        cout<<"Can't set child at" << (parent*2)<<" ";
    else
        tree[(parent*2)+1]=key;
}
int get_left_child(int index)
{
if(!tree[index].empty() && (2*index)<=maxi)
  return 2*index;
// left child doesn't exist
else
return -1;
}
int get_right_child(int index)
{

if(!tree[index].empty() && ((2*index)+1)<=maxi)
  return (2*index)+1;
// right child doesn't exist
else
return -1;
}
void inorder(int index)
{
// checking for valid index and null node
if(!tree[index].empty()&&index>0)
{
  inorder(get_left_child(index)); //visiting left subtree
  cout<<tree[index]<<" "; //visiting root
  inorder(get_right_child(index)); // visiting right subtree
}
}
void postorder(int index)
{
// checking for valid index and null node
if(!tree[index].empty()&&index>0 )
{
  postorder(get_left_child(index)); //visiting left subtree
  postorder(get_right_child(index)); //visiting right subtree
  cout<<tree[index]<<" "; //visiting root
}
}
void preorder(int index)
{
// checking for valid index and null node
if(!tree[index].empty()&&index>0 )
{
  cout<<tree[index]<<" "; // visiting root
  preorder(get_left_child(index)); //visiting left subtree
  preorder(get_right_child(index)); //visiting right subtree
}
}
int main(void)
{
    string ch;
    int i;
    cout<<"Enter root : ";
    cin>>ch;
    root(ch);
    for(i=0;;i++)
    {
        string c;string s;int n;

        cout<<"Where do you want to insert?"<<" "<<"Enter choice(left/right/stop):";
        cin>>s;
        if(s=="stop")
            break;
        else if(s=="left")
        {
            cout<<"Enter element: ";
            cin>>c;
            cout<<"With which parent do you want to connect?";
            cin>>n;
            set_left(c,n);
        }
        else if(s=="right")
        {
            cout<<"Enter element: ";
            cin>>c;
            cout<<"with which node you want to connect?";
            cin>>n;
            set_right(c,n);
        }
    }

    int j=100;
    while(tree[j].empty())
    {
        j--;
    }
    cout<<endl;
   // cout<<j<<endl;;
    for(i=1;i<10;i++)
    {
        if(j==pow(2,i)-1)
            {maxi=j;break;}
        else if((j>pow(2,i)-1) && j<=(pow(2,i+1)-1))
            {maxi=pow(2,i+1)-1;break;}
    }
    print_tree();
    //cout<<"\nmax:"<<maxi;
    cout<<"\nPreorder:\n";
    preorder(1);
    cout<<"\nPostorder:\n";
    postorder(1);
    cout<<"\nInorder:\n";
    inorder(1);
    cout<<("\n");
}
