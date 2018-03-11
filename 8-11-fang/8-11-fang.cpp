//
//  main.cpp
//  test
//
//  Created by Fang He on 2018-03-03.
//  Copyright © 2018 FreshProgrammers. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> g_step_sizes{25,10,5,1};

int get_variation_for(int n, int idx = 0)
{
    if (n == 0) return 1;
    if (n < 0) return 0;
    
    int cur_step_size = 0;
    
    
    if( idx < g_step_sizes.size() )
    {
        cur_step_size = g_step_sizes[idx];
        
        idx++;
    }
    else
        return 0;
    
  
    int max_steps = n / cur_step_size;
    
    int total_variation = 0;
    for (int i = max_steps; i >= 0; --i)
    {
        //cout << "Cur[" << idx <<"]:" << cur_step_size << " * " << i << " and remaining:" << n << endl;
        total_variation += get_variation_for(n - i * cur_step_size, idx);
    }
    return total_variation;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int in;
    cin >> in;
    int out = get_variation_for(in);
    cout << out<<endl;
    cin >> in;
    return 0;
}
