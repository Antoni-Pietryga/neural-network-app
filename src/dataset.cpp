#include "dataset.h"
#include <vector>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;

WindowGenerator::WindowGenerator(const std::string& path){
  this->data = read_csv(path);
}

void WindowGenerator::split_to_windows(int input_width, int label_width, int shift, string column_name){
    vector<vector<float>> X;
    vector<vector<float>> Y;
	vector<int> shuffled_indexes;
    
    int column_index = get_column_index(column_name);

    if (column_index != -1) {
		pair<vector<vector<float>>, vector<vector<float>>> X_Y = split_to_X_Y(input_width, label_width, shift, column_index);
		X = X_Y.first;
		Y = X_Y.second;
    }
    else {
        std::cout << "Column name not found"<<endl;
		// End application
    }

    shuffled_indexes = shuffle_indexes(X.size());
	clear_vectors();
	split_to_train_test_valid(shuffled_indexes, X, Y);

	cout<<"train size: "<<this->train_X.size()<<" records"<<endl;
	cout<<"test size: "<<this->test_X.size()<<" records"<<endl;
	cout<<"valid size: "<<this->valid_X.size()<<" records"<<endl;
}

vector<vector<string>> WindowGenerator::read_csv(string fname){
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

int WindowGenerator::get_column_index(string column_name){
	
	int column_index = -1;
    vector<string> v = this->data[0];
    for(int i=0;i<v.size();i++){
		if(v[i].compare(column_name) == 0){
			column_index = i;
			break;
		}
	}
	return column_index;
}

pair<vector<vector<float>>, vector<vector<float>>> WindowGenerator::split_to_X_Y(int input_width, int label_width, int shift, int column_index){
    vector<vector<float>> X;
    vector<vector<float>> Y;
	vector<float> x;
	vector<float> y;
	int size = this->data.size() - shift;

	for(int i=1;i<size;i+=input_width){
		if(i % shift != 1)
			continue;
		// X
		for(int j=i;j<i+input_width;j++){
			x.push_back(stof(this->data[j][column_index]));
		}
		// y
		for(int j=i+shift;j<i+shift+label_width;j++){
			y.push_back(stof(this->data[j][column_index]));
		}

		X.push_back(x);
		Y.push_back(y);
		x.clear();
		y.clear();
	}
	return {X, Y};
}

vector<int> WindowGenerator::shuffle_indexes(int size){
	vector<int> indexes;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);

    for(int i=0;i<size;i++)
		indexes.push_back(i);

    shuffle(indexes.begin(), indexes.end(), e);
	
	return indexes;
}

void WindowGenerator::clear_vectors(){
	this->train_X.clear();
    this->train_y.clear();
    this->test_X.clear();
    this->test_y.clear();
    this->valid_X.clear();
    this->valid_y.clear();

}

void WindowGenerator::split_to_train_test_valid(vector<int> shuffled_indexes, vector<vector<float>> X, vector<vector<float>> Y){
	for(int i=0;i<shuffled_indexes.size();i++){
		if((float)i/shuffled_indexes.size() <= this->train_size){
			this->train_X.push_back(X[shuffled_indexes[i]]);
			this->train_y.push_back(Y[shuffled_indexes[i]]);
		}
		else if((float)i/shuffled_indexes.size() <= this->train_size+this->test_size){
			this->test_X.push_back(X[shuffled_indexes[i]]);
			this->test_y.push_back(Y[shuffled_indexes[i]]);
		}
		else if((float)i/shuffled_indexes.size() <= this->train_size+this->test_size+this->valid_size){
			this->valid_X.push_back(X[shuffled_indexes[i]]);
			this->valid_y.push_back(Y[shuffled_indexes[i]]);
		}

    }

}
pair<vector<vector<float>>, vector<vector<float>>> WindowGenerator::get_train() { return {train_X, train_y}; }

pair<vector<vector<float>>, vector<vector<float>>> WindowGenerator::get_test() { return {test_X, test_y}; }

pair<vector<vector<float>>, vector<vector<float>>> WindowGenerator::get_valid() { return {valid_X, valid_y}; }

