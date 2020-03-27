#include <iostream> 
#include <algorithm>
#include <vector>
  
using namespace std; 
  
struct ObjectInBackpack
{ 
    int benefit;
    double weight; 
  
    ObjectInBackpack(int ben, double weig){
        benefit = ben;
        weight = weig;
    }
}; 
  
bool compare(struct ObjectInBackpack a, struct ObjectInBackpack b) 
{ 
    double ratio_a = (double) a.benefit / a.weight; 
    double ratio_b = (double) b.benefit / b.weight; 
    if(ratio_a>ratio_b){
        return true;
    }else{
        return false;
    }
} 
  
vector<double> mochilaEnteros(int M, struct ObjectInBackpack elements[], int size) 
{ 
    vector<double> solution;
    sort(elements, elements + size, compare); 

    cout<<" ORDENADO POR RATIO "<<endl;

    for (int i = 0; i < size; i++) 
    { 
        cout << elements[i].benefit << "  " << elements[i].weight << " ratio benefit/weight" << ((double)elements[i].benefit / elements[i].weight) << endl; 
    } 
   
  
    int current_weight = 0;  
  
    for (int i = 0; i < size; i++) 
    { 
        if (current_weight + elements[i].weight <= M) 
        { 
            solution.push_back(1);
            current_weight+=elements[i].weight;
            
        } 
  
        else 
        { 
            solution.push_back(0);
            break; 
        } 
        
        
    } 
    cout<<" TOTAL BACKPACK'S WEIGHT "<<current_weight<<endl;
    cout<<" OF TOTAL CAPACITY  "<<M<<endl;
  
    return solution;
} 

vector<double> mochilaFraccion(int M, struct ObjectInBackpack elements[], int size) 
{ 
    vector<double> solution;
    sort(elements, elements + size, compare); 
  
 
    for (int i = 0; i < size; i++) 
    { 
        cout << elements[i].benefit << " / " << elements[i].weight << " ratio benefit/weight: " << ((double)elements[i].benefit / elements[i].weight) << endl; 
    } 
   
  
    int current_weight = 0;  
  
    for (int i = 0; i < size; i++) 
    { 
        if (current_weight + elements[i].weight <= M) 
        { 
            solution.push_back(1);
            current_weight+=elements[i].weight;
            
        } 
  
        else 
        { 
            double fraction = (double)(M-current_weight)/elements[i].weight;
            solution.push_back(fraction);
            current_weight+=fraction*elements[i].weight;
            break; 
        } 
        
        
    } 
    cout<<" TOTAL BACKPACK'S WEIGHT "<<current_weight<<endl;
    cout<<" OF TOTAL CAPACITY  "<<M<<endl;
  
    return solution;
} 


void printVector(vector<double> solution, struct ObjectInBackpack elements[]){
    for(int i=0; i<solution.size(); i++){
        cout<<solution.at(i)<<endl;
        cout<<" weight "<<elements[i].weight<<endl;
        cout<<" benefit "<<elements[i].benefit<<endl;
    }
}
  
int main() 
{ 
    double total_capacity = 70;   
    ObjectInBackpack *element_a = new ObjectInBackpack(60, 10.0);
    ObjectInBackpack *element_b = new ObjectInBackpack(100, 20.0);
    ObjectInBackpack *element_c = new ObjectInBackpack(120, 30.0);
    ObjectInBackpack *element_d = new ObjectInBackpack(60, 30.0);

    ObjectInBackpack elements[] = {*element_a, *element_b, *element_c, *element_d}; 
    int size = sizeof(elements) / sizeof(elements[0]); 

  
    cout<<" MOCHILA CON FRACCIONES "<<endl;
    vector<double> solution = mochilaFraccion(total_capacity, elements, size); 
    printVector(solution, elements);

    cout<<endl;
    cout<<" MOCHILA CON ENTEROS "<<endl;
    solution = mochilaEnteros(total_capacity, elements, size); 
    printVector(solution, elements);
    return 0;
   
} 