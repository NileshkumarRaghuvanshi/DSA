#ifndef NODEDATA_H
#define NODEDATA_H

typedef int DATA;
class nodeData {

public:
	nodeData() {
		data = 0;
	}
	void setData(DATA data) {
		this->data = data;
	}

	DATA getData() const {
		return data;
	}

private:
	DATA data;

};

#endif
