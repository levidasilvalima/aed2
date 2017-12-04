# ifndef BRAIN_EDGE
# define BRAIN_EDGE

class BrainEdge {
private:
	int id;
	double weight;
	
public:
	BrainEdge();
	BrainEdge(int newId, double newWeight);
	
	int getId();
	double getWeight();
	
	bool operator<(BrainEdge otherBrainEdge) {
		double otherWeight = otherBrainEdge.getWeight();
		return this->weight < otherWeight;
	}
	
	bool operator>(BrainEdge otherBrainEdge) {
		double otherWeight = otherBrainEdge.getWeight();
		return this->weight > otherWeight;
	}
	
	bool operator==(BrainEdge otherBrainEdge) {
		double otherWeight = otherBrainEdge.getWeight();
		return this->weight == otherWeight;
	}
};

BrainEdge::BrainEdge() {

}

BrainEdge::BrainEdge(int newId, double newWeight) {
	this->id = newId;
	this->weight = newWeight;
}

int BrainEdge::getId() {
	return this->id;
}

double BrainEdge::getWeight() {
	return this->weight;
}

# endif
