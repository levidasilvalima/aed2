# ifndef EDGE
# define EDGE

class Edge {
private:
    int source;
    int destination;
    double weight;

public:
    Edge(int source, int destination, double weight);
    int getSource();
    int getDestination();
    double getWeight();    
};

Edge::Edge(int vertexSource, int vertexDestination, double edgeWeight) {
    this->source = vertexSource;
    this->destination = vertexDestination;
    this->weight = edgeWeight;
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
