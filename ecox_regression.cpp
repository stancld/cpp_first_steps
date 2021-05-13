#include <iostream>
#include <random>
#include <vector>

using namespace::std;

// define 


double dot_product(vector<double> x, vector<double> y){
    double res;
    for (int i = 0; i < x.size(); i++){
        res += x[i] * y[i];
    }
    return res;
}

vector<double> generate_weights(int shape){
    vector<double> weights(shape, 0.1);
    return weights;
}

double get_error(vector<double> x, double y, vector<double> w, double b){
    double y_pred = dot_product(x, w);
    y_pred += b;
    double error = (y - y_pred) * (y - y_pred);
    return error;
}

vector<double> get_w_derivatives(double error, vector<double> x){
    vector<double> w_grad(x.size(), 0.0);
    for (int k = 0; k < w_grad.size(); k++){
        w_grad[k] -= 2 * error * x[k];
    };
    return w_grad;
}

void run_epoch(vector<vector<double>> X, vector<double> Y, vector<double> w, double b){
    double tot_error = 0.0;
    double tot_b_grad = 0.0;
    vector<double> tot_w_grad(w.size(), 0.0);

    for (int i = 0; i < Y.size(); i++){
        // Get error
        double error = get_error(X[i], Y[i], w, b);
        tot_error += error;

        // Get derivatives
        tot_b_grad -= 2 * error;
        vector<double> w_grad = get_w_derivatives(error, X[i]);
        for (int k = 0; k < w_grad.size(); k++){
            tot_w_grad[k] += w_grad[k];
        };
    };
}




int main(){
    float lr;
    int epochs;

    // Set input parameters
    cout << "Set learning rate: ";
    cin >> lr;

    cout << "Set a number of epochs: ";
    cin >> epochs;

    // Initialize weights, biases and examples
    double bias = 0.0;
    vector<double> weight = generate_weights(3);
    cout << "bias = " << bias << " \n";
    cout << "weights = " << weight[1] << " \n";

    for (int epoch = 0; epoch < epochs; epoch++){
        cout << "Hello";
    };
}