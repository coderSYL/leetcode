// C++
// leetcode 1600
// https://leetcode-cn.com/problems/throne-inheritance/
// 思路:
// 参考了别人的题解
// 用一个结构体Node来代表一个人，里面有人的名字，人的孩子
// 用一个全局变量king_来表示最初的国王
// 用一个unordered_map来通过string name获得那个人的Node*

class ThroneInheritance {
public:
    ThroneInheritance(string kingName): king_(new Node(kingName)) {
        getNodeByName_[kingName] = king_;
    }

    ~ThroneInheritance() {
    	dieOut(king_);
    }
    
    void birth(string parentName, string childName) {
    	getNodeByName_[childName] = new Node(childName);
    	getNodeByName_[parentName]->children.push_back(getNodeByName_[childName]);
    }
    
    void death(string name) {
    	getNodeByName_[name]->alive = false;
    }
    
    vector<string> getInheritanceOrder() {
    	if(!king_)	return {};
    	vector<string> res;
    	preOrder(king_, res);
    	return res;
    }

private:
	struct Node {
    	string name;
    	bool alive;
    	vector<Node*> children;
    	Node(const string& name) : name(name), alive(true) {}
	};

	Node *king_;

	unordered_map<string, Node*> getNodeByName_;

	void preOrder(Node *root, vector<string>& res){
		if(root->alive)	res.push_back(root->name);
		for(auto child : root->children)	preOrder(child, res);
	}

	void dieOut(Node* a){
		if(!a)	return;
		for(auto& child: a->children)	dieOut(child);
		delete a;
	}
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */