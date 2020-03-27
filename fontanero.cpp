#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 
  
  
struct job{
    int satisfaction_level; //can be 1, 2 or 3 , 0 = undeclared
    int time; 
    int waiting_time;

    job(int tim, int wait, int sat){
        time = tim;
        waiting_time = wait;
        satisfaction_level = sat;
    }
};

int getSatisfactionLevel(int waiting_time, int time){
    if(time*2>waiting_time){
        return 1;
    }else if(time*3<waiting_time){
        return 2;
    }else{
        return 3;
    }
}

vector<job> executeJobs(vector<int> to_execute) 
{ 
    int total_time = 0;
    vector<job> solution;
    
    sort(to_execute.begin(), to_execute.end());

    for(int i=0; i<to_execute.size(); i++){
        solution.push_back( job(to_execute.at(i), total_time,  getSatisfactionLevel(total_time, to_execute.at(i))));

        total_time += to_execute.at(i);

        
    }
    return solution;
  
} 

  
void printJobs(vector<job> to_print){
    for(int i=0; i<to_print.size(); i++){
        cout<<" trabajo no "<<i<<endl;
        cout<<" tiempo de ejecución "<<to_print.at(i).time<<endl;
        cout<<" tiempo de espera "<<to_print.at(i).waiting_time<<endl;
        cout<<" nivel de satisfacción "<<to_print.at(i).satisfaction_level<<endl;
        cout<<endl;
    }
}

int main(int argc, const char* argv[]) 
{ 
    vector<int> to_do; 
    to_do.push_back(5);
    to_do.push_back(4);
    to_do.push_back(10);
    to_do.push_back(2);
    vector<job> solution = executeJobs(to_do);
    printJobs(solution);
    return 0; 
} 