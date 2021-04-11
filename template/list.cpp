#include <iostream>
#include <list>

using std::list;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    list<int> mylists{1, 3, 4, 5, 6, 7};

    auto it = mylists.find(7);
    mylists.splice(mylists.begin(), mylists, it);
    for(auto node : mylists)
        cout << node << " ";
    cout << endl;

    return 0;
}
