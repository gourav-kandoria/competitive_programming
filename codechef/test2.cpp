#include <iostream>
#include <list>

using namespace std;

int main(){
    int t;
    cin >> t;
    int num_of_chocs;
    list<int> max_list;
    int max_sweetness;
    int num;
    
    while (t-->0){
        max_list.clear();
        max_sweetness = 0;
        num = 0;
        cin >> num_of_chocs;
        int sweetness[num_of_chocs];
        int result;
        for (int i=0;i<num_of_chocs;i++){
            cin >> sweetness[i];
            if (max_sweetness < sweetness[i] ) {
                max_sweetness = sweetness[i];
                max_list.clear();
                max_list.push_back(i);
                num = 1;
            }
            else if (max_sweetness == sweetness[i]){
                max_list.push_back(i);
                num += 1;
            }
        }
        if (num==1){
            result = num_of_chocs/2;
        }
        else{
            result = num_of_chocs/2 - (max_list.back() - max_list.front()) ;
        }
        if (result < 0){
            result = 0;
        }
        cout << result << endl;
    }
    return 0;
}

