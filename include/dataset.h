#ifndef WINDOW_GENERATOR_H
#define WINDOW_GENERATOR_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
/** @brief The class responsible for generating dataset.
*/
class WindowGenerator{

public:
/** Constructor. Read CSV data from file.
@param path - path to csv file.
**/
    explicit WindowGenerator(const std::string& path);
/** Function to get test data.
@return pair of test targets and values.
**/
    pair<vector<vector<float>>, vector<vector<float>>> get_test();
/** Function to get train data.
@return pair of train targets and values.
**/
    pair<vector<vector<float>>, vector<vector<float>>> get_train();
/** Function to get validation data.
@return pair of validation targets and values.
**/
    pair<vector<vector<float>>, vector<vector<float>>> get_valid();
/** Function to split data to windows.
@param input_width - length of input vector.
@param label_width - length of prediction vector.
@param shift - shift of prediction value.
@param column_name - column name on which we should create dataset.
**/
    void split_to_windows(int input_width, int label_width, int shift, string column_name);
/** Function to get column index by column name.
@param column_name - column name which index we looking for.
@return column index.
**/
int get_column_index(string column_name);
/** Function to split data to targets and values.
@param input_width - length of input vector.
@param label_width - length of prediction vector.
@param shift - shift of prediction value.
@param column_index - column index on which we should create dataset.
@return pair of all targets and values vectors.
**/
pair<vector<vector<float>>, vector<vector<float>>> split_to_X_Y(int input_width, int label_width, int shift, int column_index);

private:
/** Function to read and load csv file.
@param fname - file name.
@return vector of loaded data as strings.
**/
vector<vector<string>> read_csv(string );
/** Function to get column index by column name.
@param column_name - column name which index we looking for.
@return shuffled indexes.
**/
vector<int> shuffle_indexes(int size);
/** Function to clear all vectors.
**/
void clear_vectors();
/** Function to split data to train test and valid.
**/
void split_to_train_test_valid(vector<int> shuffled_indexes, vector<vector<float>> X, vector<vector<float>> Y);

    vector<vector<string>> data;
    vector<vector<float>> test_X;
    vector<vector<float>> train_X;
    vector<vector<float>> valid_X;

    vector<vector<float>> test_y;
    vector<vector<float>> train_y;
    vector<vector<float>> valid_y;

    float train_size = 0.7;
    float test_size = 0.15;
    float valid_size = 0.15;

};
#endif //WINDOW_GENERATOR_H
