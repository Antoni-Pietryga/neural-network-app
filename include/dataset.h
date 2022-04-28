#pragma once

#include <iostream>
#include <torch/torch.h>
#include <string>
#include <vector>
/** @brief The class responsible for holding data container.
*/
struct Data : torch::data::datasets::Dataset<Data> {

public:
	/** The mode in which the dataset is loaded
	*/
    	enum Mode { kTrain, kTest };
    	/** Constructor. Initialize path and mode.
	@param root - file path.
	@param mode - enum value, mode of dataset.  
        */
	explicit Data(const std::string& root, Mode mode = Mode::kTrain);

    	/** Returns the `Example` at the given `index`.
	@param index - index of tensor. 
	*/
    	torch::data::Example<> get(size_t index) override;

    	/** Returns the size of the dataset.
	*/
    	torch::optional<size_t> size() const override;

    	/** Returns all values stacked into a single tensor.
	*/    	
	const torch::Tensor& values() const;
    	/** Returns true if this is the training mode.
	*/
    	bool is_train() const noexcept;

    	/** Returns all targets stacked into a single tensor.
	*/
    	const torch::Tensor& targets() const;

 private:
    torch::Tensor values_;
    torch::Tensor targets_;
    Mode mode_;
};

