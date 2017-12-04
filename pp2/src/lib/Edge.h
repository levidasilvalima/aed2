# ifndef EDGE
# define EDGE

template<typename T>
class Edge {
private:
    T source;
    T destination;
    double weight;

public:
    Edge(T source, T destination, double weight);
    Edge();
    T getSource();
    T getDestination();
    double getWeight(); 

	bool operator>(Edge<T> otherEdge) {
		double otherWeight = otherEdge.getWeight();
    
        if (weight > otherWeight) {
        	return true;
        }
        return false;		        
    }  

	bool operator<(Edge<T> otherEdge) {
		double otherWeight = otherEdge.getWeight();
    
        if (weight < otherWeight) {
        	return true;
        }
        return false;		        
    }  

    bool operator==(Edge<T> otherEdge) {
		T otherSource = otherEdge.getSource();
		T otherDestination = otherEdge.getDestination();
		double otherWeight = otherEdge.getWeight();
    
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

template<typename T>
Edge<T>::Edge(T vertexSource, T vertexDestination, double edgeWeight) {
    this->source = vertexSource;
    this->destination = vertexDestination;
    this->weight = edgeWeight;
}

template<typename T>
Edge<T>::Edge() {
}

template<typename T>
T Edge<T>::getSource() {
    return this->source;
}

template<typename T>
T Edge<T>::getDestination() {
    return this->destination;
}

template<typename T>
double Edge<T>::getWeight() {
    return this->weight;
}

# endif
