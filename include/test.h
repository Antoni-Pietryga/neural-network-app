#include "train_params.h"
#include "dataset.h"
#include "neural_net.h"

using namespace std;
class Test{
public:
	string test_path;
	TrainParameters params = TrainParameters(30, 20, 50, 0.001);
	string model_path;
	
	explicit Test(string test_path_, const TrainParameters &params_, string model_path_);
	void test();
};
