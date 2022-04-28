#include "train_params.h"
#include "dataset.h"
#include "neural_net.h"

using namespace std;
/** @brief Required polymorphism implementation.
*/
class TestBase{
public:
    virtual float test()=0;
};
/** @brief The class responsible for twst pipeline.
*/
class Test : TestBase{
public:
	string test_path;
	string model_path;

	TrainParameters params = TrainParameters(30, 20, 50, 0.001);
	/** Constructor. Initialize params and model_path.
	**/
	explicit Test(string test_path_, const TrainParameters &params_, string model_path_);
	/** Run test on selected file.
	@return accuracy of predictions in selected file.
	*/
	float test();
};
