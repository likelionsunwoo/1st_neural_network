#include<iostream>
#define MAX2(a,b) (a) > (b) ? (a) : (b)


class Neuron
{
public: 
	Neuron()
		: w_(2.0), b_(1.0)
	{}

	Neuron(const double& w_input, const double& b_input)
		: w_(w_input), b_(b_input)
	{}

public:
	double w_; //weight of one input
	double b_; //bias of

	double getAct(const double& x)
	{
		//for linear or identity activation functions
		return x;

		//for ReLU activation functions
		//return MAX2(0.0, x);
	}
	double feedForward(const double& input)
	{
		//output y = f(\sigma)
		// \sigma = w_ * input x +b
		// for multiple inputs,
		// \sigma = w0_ * x_0+ w1_ * x_1 + ..... + b 
		const double sigma = w_ * input + b_;

		return getAct(sigma);
	}
	void feedForwardAndPrint(const double& input)
	{
		printf("%f %f \n",input,feedForward(input));
	}

};
void main()
{
	//initialize my_neuron
	Neuron my_neuron(2.0,1.0);
	//my_neuron.w_ = 2.0;//가장 적절한 w 와 b를 구해가는 AI의 훈련과정이 중요하다.
	//my_neuron.b_ = 1.0;
	
	for (double input = 0; input < 3.0; input +=1.0) 
	{
		my_neuron.feedForwardAndPrint(input);
	}
	
	/*my_neuron.feedForwardAndPrint(0.0);
	my_neuron.feedForwardAndPrint(1.0);
	my_neuron.feedForwardAndPrint(2.0);*/
	
	//std::cout << "Input = 0.0은 " << my_neuron.feedForward(0.0) << std::endl;
	//std::cout << "Input = 1.0은 " << my_neuron.feedForward(1.0) << std::endl;
	//std::cout << "Input = 2.0은 " << my_neuron.feedForward(2.0) << std::endl;
	//std::cout << "Input = 3.0은 " << my_neuron.feedForward(3.0) << std::endl;
}