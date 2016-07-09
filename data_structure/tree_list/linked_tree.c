struct Node {
	struct Node* parent;
	struct NodeList* children;
	struct Node* previous;
	struct Node* next;
	
	void* data;
};

struct NodeList {
	
};