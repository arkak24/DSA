#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

struct Jobs{
      int id;
      int deadline;
      int profit;

      static bool cmp(const Jobs &j1, const Jobs &j2){
            if(j1.profit > j2.profit) return true;
            else return false;
      }
};

std::pair<int, int> profit_fn(std::vector<Jobs> &job){
      std::sort(job.begin(), job.end(), Jobs::cmp);

      int max_d = -1;
      for(int i = 0; i < job.size(); i++){
            if(max_d < job[i].deadline){
                  max_d = job[i].deadline;
            }
      }

      int total_profit = 0;
      int count = 0;

      std::vector<int> hash(max_d+1, -1);
      for(int i = 0; i < job.size(); i++){
            for(int j = job[i].deadline; j >= 1; j--){ // from that deadline we are checking if any day free before
                  if(hash[j] == -1){
                        count++;
                        hash[j] = job[i].id;
                        total_profit += job[i].profit;
                        break;
                  }
            }
      }
      return {count, total_profit};
}

int main(){
      std::vector<Jobs> job = {
            // {1, 4, 20},
            // {2, 5, 60},
            // {3, 6, 70},
            // {4, 6, 65},
            // {5, 4, 25},
            // {6, 2, 80},
            // {7, 2, 10},
            // {8, 2, 22}
            { 1,  3,  50},
            { 2,  5,  20},
            { 3,  1, 100},
            { 4,  5,  60},
            { 5,  7,  80},
            { 6,  3,  10},
            { 7,  2,  75},
            { 8,  7,  40},
            { 9,  2,  90},
            {10, 10, 15},
            {11,  9, 85},
            {12,  8, 30},
            {13,  4, 55},
            {14,  6, 65},
            {15,  3, 45},
            {16, 10, 70},
            {17,  6, 25},
            {18,  4, 95},
            {19,  1, 35},
            {20,  8, 50}
      };

      std::pair<int, int> ans = profit_fn(job);

      std::cout << "count: " << ans.first << ", profit: " << ans.second << std::endl;

      return 0;
}
