// This is the custom file that was built as a test to implement struct inside a class

#include <isotream>
using namespace std;

class Matrix{
public:
	Matrix(){
		// this is the constructor of this class

		// for type 2 operation
		shape_vec = decode_shape(?input?);
		allocate_memory(shape_vec);
		assign_val(?input?);
	};
	~Matrix();{
		// destructor of this class
	}
	void assign_shape(int shape[2]){
		shape_vec[0] = shape[0]; shape_vec[1] = shape[1];
	}
	std::vector<int> get_shape(){
		return shape_vec;
	}
	void assign_val(Matrix A){
		// code to assign the value to the matrix
		// this is something I am not able to build as of now
	}
private:
	struct row_array{
		int data[??]; // what will be the data length, this is the
		// length of each row. How to define this
		struct row_array *next;
	};
	std::vector<int> shape_vec(2); // defines the shape of the matrix
};

int main(){
	// Assume we already have matrices A and B
	Matrix mat;
	// as you can see we need to currently do 4 more lines of code,
	// this is something I want to remove
	int shape_curr[2];
	shape_curr[0] = A.get_shape()[0];
	shape_curr[1] = B.get_shape()[1];
	mat.assign_shape(shape_curr);
	// I would like to do this only
	mat.assign_val(CoreOps::mat_mul(A, B)); // type 1
	// or best would be something like this
	mat = CoreOps::mat_mul(A, B) // type 2
}