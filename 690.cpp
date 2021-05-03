/*
 * C++
 * leetcode690
 * url: https://leetcode-cn.com/problems/employee-importance/
 */

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
	
	int getImportance(Employee* one){
		return one->importance;
	}
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size(), temp =0, res = 0, num_down = 0;
        Employee* wanted = nullptr;
        int ids[size];
        for(int i =0; i<size; i++)
        	ids[i] = employees[i]->id;
        
        vector<int> needed;
        needed.push_back(id);
        while(!needed.empty()){
        	temp = needed.back();
        	needed.pop_back();
        	for(int i = 0; i<size; i++){
        		if(ids[i] ==temp){
        			wanted = employees[i];
        			break;
        		}
        	}
        	res += getImportance(wanted);
        	num_down = wanted->subordinates.size();
        	for(int i = 0; i<num_down; i++)
        		needed.push_back(wanted->subordinates[i]);
        }
        return res;
    }
};