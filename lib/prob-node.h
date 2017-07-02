#include <utility>

class ProbNode{
	typedef int (*int_func_ptr_)(int);
	typedef int (*merger_func_ptr_)(int*,int args);
	public:
		/*-----Constructors-----*/
		// Default Constructor
		ProbNode();  

		// Full constructor.
		// action function pointer is what the node does to data it is provided
		// connected nodes is the maximum number of connected nodes
		// node list is a bunch of pointers to said nodes.
		// node list will only be loaded up to the first null pointer.
		ProbNode( int_func_ptr_ action , merger_func_ptr_ merge_process,
			  int connected_nodes, ProbNode** node_list);

		
		
		/*-----Accessors-----*/

		// Evaluates the node for a given value
		// Returns a pair of the resulting int, and a pointer to the pointerlist
		// Don't use the raw pointer for much of anything. There are other
		// functions for that.
		std::pair<int, ProbNode**>Evaluate(int value);

		// returns the number of unallocated node pointers.
		int GetFreeNodePtrs();

		// returns the number of used node pointers
		int GetUsedNodePtrs();

		// returns the maximum number of node pointers.
		int GetMaxNodePtrs();


		// returns a node at index index_.
		// raises an exception if index_ is invalid.
		ProbNode* GetNodePtrAtIndex( int index);

		// returns a function pointer to the action function currently in use.
		int_func_ptr_ GetNodeAction();


	

		/*-----Mutators-----*/

		// Adds a connected node to the first open location in node list
		// new node is the node to be added
		// returns a integer corresponding to the number of unfilled nodes left.
		int PushNodePtr( ProbNode* new_node);

		// Removes the last node in the list.
		// Returns the removed node.
		ProbNode* PopNodePtr();

		// Removes the node at the specified index.
		// Returns the value of said node.
		// Raises an exception if index_ is invalid.
		ProbNode* RemoveFromIndex(int index);

		// Swaps a node for a diferent one.
		// search_node_ is the node to look for
		// new_node_ is the one to swap it with
		// returns search_node_ if the node was found and swapped, otherwise NULL.
		// Raises an exception if search_node_ is null.
		ProbNode* SwapNodePtr( ProbNode* search_node, ProbNode* new_node);
		
		// Tries to reallocate the node pointer list
		// If the new_length_ is too short, shrinks as much as it can.
		// Returns the actual new length.
		// Raises exception if allocation fails, or newLength is invalid.
		int ReallocNodePtrList(int newLength);

		// Swaps the node action with the one provided.
		// Takes the new action as argument, returns old action.
		int_func_ptr_ SetNodeAction(int_func_ptr_ new_action);

		// Accepts a request to be taken as a child.
		int AcceptParent(ProbNode* target_node);

		
	private:
		// Stores all nodes that link to this one.
		ProbNode** parents_;

		// Stores all nodes that this one links to.
		ProbNode** children_;

		// Requests permission to add node as a child.
		int RequestChild(ProbNode* target_node);
};
