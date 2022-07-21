// This problem was asked by Google.

// Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s), which deserializes the string back into the tree.

// For example, given the following Node class

//class Node :
//    def __init__(self, val, left = None, right = None) :
//    self.val = val
//    self.left = left
//    self.right = right

//    The following test should pass :

// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'

#include <iostream>
#include <cmath>
#include <assert.h>
#include <sstream>
#include <queue>

class Node {
public:
	int data;
	class Node* left;
	class Node* right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

class Codec {
	std::queue<std::string>q;
	Node* deserialization(void) {
		if (q.empty()) {
			return nullptr;

		}
		std::string temp = q.front();
		q.pop();
		if (temp == "&") {
			return nullptr;
		}

		Node* root = new Node(atoi(temp.c_str()));

		root->left = deserialization();
		root->right = deserialization();
		return root;

	}

	std::string s;
	void ser(Node* root) {
		if (root == nullptr) {
			s += "&/";
			return;
		}
		s += std::to_string(root->data) + "/";
		ser(root->left);
		ser(root->right);
	}

public:

	// serializes object to string
	std::string serialize(Node* root) {
		s = "";
		ser(root);
		return s;
	}

	// deserializes string into object
	Node* deserialize(std::string data, int index = 0) {
		std::string temp{};
		for (int i = 0; i < data.size(); i++) {
			if (data[i] == '/') {
				q.push(temp);
				temp = "";
				continue;
			}
			temp += data[i];
		}
		return deserialization();

	}

};


int main() {
	class Node* root = new Node(5);

	root->left = new Node(7);
	root->right = new Node(3);

	root->left->left = new Node(9);
	root->left->right = new Node(6);

	Codec* ser = new Codec();
	Codec* deser = new Codec();
	std::string bintreestr = ser->serialize(root);
	Node* bintreeobj = deser->deserialize(bintreestr);

	 assert(bintreeobj->left->left->data == 9);

	 std::cout << std::to_string(bintreeobj->left->left->data);


	return 0;
}

// serializing into binary would've been way easier and I didn't want to store binary 
// in a string because I thought it'd be cheating.
// I needed help on that one... It would have taken me longer than a day if I had done it alone.
