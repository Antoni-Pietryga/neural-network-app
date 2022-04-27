#include "dataset.h"
#include <vector>
using namespace std;
namespace {

vector<vector<string>> read_csv(string fname){
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		cout<<"Could not open the file\n";

	return content;
}

std::pair<torch::Tensor, torch::Tensor> read_data(const std::string& path, bool train) {
  
  vector<vector<string>> content = read_csv(path);
  const auto num_samples = content.size() - content.size()%100;
  auto targets = torch::empty(num_samples, torch::kInt64);
  auto values = torch::empty({num_samples, 1, 500}, torch::kFloat);
  int64_t label = 0;
  for(int i=0;i<num_samples;i++){
    if(i == 0)
	continue;    
    for(int j=0;j<content[i].size();j++){
      if(j == 500){
	float val = stod(content[i][j]);
        targets[i] =  val;
      }
      else{
	float val = stod(content[i][j]);
        values[i][0][j] = val;
      }
    }
  }
  return {values, targets};
}
}  // namespace

Data::Data(const std::string& root, Mode mode) : mode_(mode) {
  auto data = read_data(root, mode == Mode::kTrain);

  values_ = std::move(data.first);
  targets_ = std::move(data.second);
}

torch::data::Example<> Data::get(size_t index){
  return {values_[index], targets_[index]};
}

torch::optional<size_t> Data::size() const { return (int)targets_.sizes()[0]; }

bool Data::is_train() const noexcept { return mode_ == Mode::kTrain; }

const torch::Tensor& Data::values() const { return values_; }

const torch::Tensor& Data::targets() const { return targets_; }

