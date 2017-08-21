#include <boost/graph/adjacency_list.hpp>
#include <boost/type_traits/is_same.hpp>
#include <vector>

class BayesianNetworkINT{

	private:
		typedef int(*merge_function)(std::vector<boost::vectS>);
		
		typedef boost::adjacency_list<boost::vecS, boost::vecS, 
					      boost::bidirectionalS, merge_function> graphcontainer;
		graphcontainer main_graph;

		

	
	public:
		/**AddLinkage: Adds a link to the internal graphcontainer between two nodes.
		 * from_node: Vertex Descriptor where the link originates
		 * to_node: Vertex Descriptor where the link terminates.
		 */
		bool AddLinkage(graphcontainer::vertex_descriptor from_node, 
				graphcontainer::vertex_descriptor to_node);
	
		/** AddNode:
		 *  Adds a node with the specified merge_function attached.
		 *  Returns a vertex descriptor for that node, that can be used to attach edges.
		 */
		graphcontainer::vertex_descriptor AddNode(merge_function merger_function);
		
		/** CheckGraphValidity:
		 *  Makes sure that the graph is a true DAG graph.
		 */
		bool CheckGraphValidity();
	
		/** EvaluateGraph
		 *  Evaluates the graph, starting at the locations specified by in_vectors, and returning
		    a vector of values evaluated at the out_vectors locations.
		 */
		std::vector<int> EvaluateGraph(vector<graphcontainer::vertex_descriptor> in_vectors,
					       vector<graphcontainer::vertex_descriptor> out_vectors);
};

bool BayesianNetworkINT::AddLinkage(graphcontainer::vertex_descriptor from_node,
				   graphcontainer::vertex_descriptor to_node){
	return boost::add_edge(from_node, to_node, this->main_graph).second;
};

BayesianNetworkINT::graphcontainer::vertex_descriptor 
BayesianNetworkINT::AddNode(merge_function merger_function){
	graphcontainer::vertex_descriptor new_node = boost::add_vertex(this->main_graph);
	this->main_graph[new_node] = merger_function;
	return new_node;
}





