#include <boost/graph/adjacency_list.hpp>


class BayesianNetworkINT{

	private:
		typedef int(*merge_function)(boost::vecS*, size_t);
		
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
		graphcontainer::vertex_descriptor AddNode(merge_function merger_function);
		bool CheckGraphValidity();
		int EvaluateGraph(graphcontainer::vertex_descriptor* in_vectors, size_t num_in,
				  graphcontainer::vertex_descriptor* out_vectors, size_t num_out);
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





