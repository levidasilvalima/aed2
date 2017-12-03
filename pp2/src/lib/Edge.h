# ifndef EDGE
# define EDGE

class Edge {
private:
    int source;
    int destination;
    double weight;

public:
    Edge(int source, int destination, double weight);
    Edge();
    int getSource();
    int getDestination();
    double getWeight(); 

	bool operator>(Edge otherEdge) {
		double otherWeight = otherEdge.weight;
    
        if (weight > otherWeight) {
        	return true;
        }
        return false;		        
    }  

	bool operator<(Edge otherEdge) {
		double otherWeight = otherEdge.weight;
    
        if (weight < otherWeight) {
        	return true;
        }
        return false;		        
    }  

    bool operator==(Edge otherEdge) {
		int otherSource = otherEdge.source;
		int otherDestination = otherEdge.destination;
		double otherWeight = otherEdge.weight;
    
        if (source == otherSource) {
            if (destination == otherDestination) {
                if (weight == otherWeight) {
                    return true;
                }
            }
        }
        return false;		        
    }  
};

Edge::Edge(int vertexSource, int vertexDestination, double edgeWeight) {
    this->source = vertexSource;
    this->destination = vertexDestination;
    this->weight = edgeWeight;
}

Edge::Edge() {
    this->source = -1;
    this->destination = -1;
    this->weight = -1;
}

int Edge::getSource() {
    return this->source;
}

int Edge::getDestination() {
    return this->destination;
}

double Edge::getWeight() {
    return this->weight;
}

# endif
