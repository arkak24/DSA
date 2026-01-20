#include <iostream>
#include <vector>
#include <algorithm>

int main(){
      std::vector<int> jobs = {3, 1, 4, 2, 5};
      // {1, 2, 3, 4, 5}

      std::sort(jobs.begin(), jobs.end());

      int wt = 0;
      int temp = 0;

      for(int i = 0; i < jobs.size()-1; i++){
            temp += jobs[i];
            wt += temp;
      }

      std::cout << "Avg. wt: " << (double)wt/jobs.size() << std::endl;

      return 0;
}
